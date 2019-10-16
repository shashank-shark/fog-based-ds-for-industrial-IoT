

// //
// //  A minimal TCP client using the ZMQ API. This demonstrates a
// //  useful mechanism for bridging a ZMQ based system out to other
// //  TCP based systems.
// //

// #include "czmq.h"


// int main (void)
// {
//     zctx_t *ctx = zctx_new();
//     void *sock = zsocket_new(ctx, ZMQ_STREAM);
//     int rc = zsocket_connect(sock, "tcp://127.0.0.1:5555");
//     if (rc != 0)
//         printf ("%s", zmq_strerror(zmq_errno()));
//     assert(rc == 0);

//     // Retrieve the socket identity. This is important in this
//     // particular scenario because when sending data using a
//     // 'ZMQ_STREAM' socket the implementation uses the first
//     // frame as the *identity* to route the message to. The ZMQ
//     // implementation strips off this first frame before sending
//     // the data to the endpoint.
//     //char *identity = zsocket_identity (sock);

//     // Must currently resort to the libzmq low-level lib to obtain
//     // raw identity information because CZMQ is returning the binary
//     // identity data as a char* and often there is 0 in the data which
//     // prematurely terminates the char* data.
//     uint8_t id [256];
//     size_t id_size = 256;
//     rc = zmq_getsockopt (sock, ZMQ_IDENTITY, id, &id_size);
//     assert (rc == 0);

//     zframe_t *frame;
//     while (!zctx_interrupted) {

//         zmsg_t *msg = zmsg_new ();
//         // Supply ZMQ with the identity to route the message to.
//         zmsg_addmem (msg, id, id_size);
//         // add message data.
//         zmsg_addstr (msg, "Hello");
//         zmsg_send(&msg, sock);


//         // When receiving TCP data, a 'ZMQ_STREAM' socket shall 
//         // prepend a frame containing the *identity* of the 
//         // originating peer to the message before passing it to 
//         // the application. Messages received are fair-queued from 
//         // among all connected peers.
//         //
//         // So in a multi-connection environment our simple
//         // assumption that we will receive a reply from the
//         // endpoint we just sent a message to is naive but will
//         // suffice for this simple test.

//         // Read off the *identity* first
//         frame = zframe_recv (sock);
//         if (!frame)
//             break; // interrupted
//         zframe_destroy (&frame);

//         // Now read off the message.
//         char *response = zstr_recv (sock);
//         printf ("Response: %s\n", response);
//         free (response);

//         // crude delay between consequtive requests
//         zclock_sleep (2000);
//     }

//     zctx_destroy (&ctx);
//     return 0;
// }