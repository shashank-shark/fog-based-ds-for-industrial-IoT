#include <czmq.h>
#include <iostream>
#include <unistd.h>

#define NBR_CLIENT 10
#define NBR_WORKER 3
#define WORKER_READY    "READY"


static void *
client_task (void *args)
{
    zctx_t *ctx = zctx_new();
    void *client = zsocket_new (ctx, ZMQ_REQ);

    zsocket_connect (client, "ipc://frontend.ipc");

    // we are sending string here but not zframe
    zstr_send (client, "HELLO");
    char *reply = zstr_recv (client);

    if (reply) {
        std::cout << "Client : " << reply << std::endl;
        free (reply);
    }

    zctx_destroy (&ctx);
    return NULL;
}

int main (void)
{

    int client_nbr = 0;
    for (client_nbr = 0; client_nbr < NBR_CLIENT; client_nbr ++)
    {
        zthread_new (client_task, NULL);
    }

    while (true) {
       continue;
    }

    return 0;
}