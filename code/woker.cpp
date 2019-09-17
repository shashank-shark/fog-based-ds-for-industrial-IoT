#include <czmq.h>
#include <iostream>
#include <unistd.h>

#define NBR_CLIENTS 10
#define NBR_WORKERS 3
#define WORKER_READY    "READY"

static void *
woker_task (void *args)
{

    zctx_t *ctx = zctx_new();
    void *worker = zsocket_new (ctx, ZMQ_REQ);

    zsocket_connect (worker, "ipc://backend.ipc");

    zframe_t *frame = zframe_new (WORKER_READY, strlen (WORKER_READY));
    zframe_send (&frame, worker, 0);

    while (1)
    {
        zmsg_t *msg = zmsg_recv (worker);
        if (!msg)
        {
            break;
        }

        zframe_print (zmsg_last (msg), "WORKER: ");
        zframe_reset (zmsg_last(msg), "OK", 2);
        zmsg_send (&msg, worker);
    }

    zctx_destroy (&ctx);
    return NULL;
}

int main (void)
{

    int nbr_wokers = 0;
    for (nbr_wokers = 0; nbr_wokers < NBR_WORKERS; nbr_wokers ++)
    {
        zthread_new (woker_task, NULL);
    }

    while (true)
    {
        continue;
    }

    return 0;
}