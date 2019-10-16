#include "zhelpers.h"
#include <inttypes.h>

int main (void)
{

    void *ctx = zmq_ctx_new();
    assert(ctx);

    void *socket = zmq_socket (ctx, ZMQ_STREAMER);
    assert (socket);

    int rc = zmq_bind (socket, "tcp://*:4545");
    assert (rc == 0);

    uint8_t id[256];
    size_t id_size = 256;

    uint8_t raw[256];
    size_t raw_size = 256;

    while (1)
    {
        id_size = zmq_recv (socket, id, 256, 0);

        do {
            raw_size = zmq_recv (socket, raw, 256, 0);
            assert (raw_size >=0);
        } while (raw_size == 256);

        printf ("%"PRIu8"\n", raw);
    }

    return 0;
}