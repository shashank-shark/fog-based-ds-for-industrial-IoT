
//
//  Minimal TCP server using 0MQ
//

#include "czmq.h"


int main (void)
{
    zctx_t *ctx = zctx_new();
    void *sock = zsocket_new (ctx, ZMQ_STREAM);

    int rc = zsocket_bind (sock, "tcp://*:5555");
    assert (rc != -1);

    while (!zctx_interrupted) {

        //  Get connection client identity so we can instruct
        // router socket which client to send the response to.
        zframe_t *frame = zframe_recv(sock);
        if (!frame)
            break;       //  Ctrl-C interrupt

        // Read the message
        char *request = zstr_recv (sock);
        printf ("Received: %s\n", request);
        free (request);

        // Send response
        zframe_send (&frame, sock, ZFRAME_MORE + ZFRAME_REUSE);
        zstr_send (sock, "World!");
    }
    zctx_destroy (&ctx);
    return 0;
}