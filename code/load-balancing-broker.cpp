#include <czmq.h>

#include <iostream>

#define NBR_WORKERS 3
#define NBR_CLIENTS 10
#define WORKERS_READY   "READY"

int main (void)
{

    int client_nbr = 0;
    client_nbr = NBR_CLIENTS;

    zctx_t *ctx = zctx_new();
    void *frontend = zsocket_new (ctx, ZMQ_ROUTER);
    void *backend = zsocket_new (ctx, ZMQ_ROUTER);

    // init the IPC communications
    zsocket_bind (frontend, "ipc://frontend.ipc");
    zsocket_bind (backend, "ipc://backend.ipc");

    // Queue for available workers
    zlist_t *workers = zlist_new();

    // poll
    while (1)
    {
        zmq_pollitem_t items[] = {
            { backend, 0, ZMQ_POLLIN, 0 },
            { frontend, 0, ZMQ_POLLIN, 0 }
        };

        // poll the frontend only if we have available workers
        int rc = zmq_poll (items, zlist_size (workers) ? 2 : 1, -1);
        if (rc == -1)
        break;

        // handle workers on backend
        if (items[0].revents & ZMQ_POLLIN)
        {
            zmsg_t *msg = zmsg_recv (backend);
            
            if (!msg)   break;

            zframe_t *identity = zmsg_pop(msg);
            zframe_t *delimeter = zmsg_pop (msg);
            zframe_destroy (&delimeter);

            zlist_append (workers, identity);

            // now msg has Data at its top
            zframe_t *frame = zmsg_first(msg);
            if (memcmp (zframe_data(frame), WORKERS_READY, strlen (WORKERS_READY)) == 0)
            {
                zmsg_destroy (&msg);
            }
            else
            {
                zmsg_send (&msg, frontend);
                if (--client_nbr == 0) {
                    break;
                }
            }
        }
        if (items[1].revents & ZMQ_POLLIN)
        {
            zmsg_t *msg = zmsg_recv (frontend);

            if (msg)
            {
                // i.e constructing the frame [ID, 0, Data]
                zmsg_pushmem (msg, NULL, 0);
                zmsg_push (msg, (zframe_t *)zlist_pop(workers));
                zmsg_send (&msg, backend);
            }
        }

    }

    while (zlist_size(workers))
    {
        zframe_t *frame = (zframe_t *)zlist_pop (workers);
        zframe_destroy (&frame);
    }

    zlist_destroy (&workers);
    zctx_destroy (&ctx);

    return 0;
}