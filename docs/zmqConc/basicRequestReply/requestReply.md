# A basic Request-Reply `server-client` program

Here we shall send the word `Hello` to the server and we expect a `World` as reply.

### Request Client ( rclient.c )

```c
#include "zhelpers.h"

int main (void)
{
    
    void *context = zmq_ctx_new ();

    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5000");

    // let us send 10 requests and expect 10 replies
    int req = 0;
    for (req = 0; req != 10; req ++)
    {
        s_send (requester, "Hello");

        // now expect a reply back from server
        char *string;
        string = s_recv (requester);
        printf ("Recieved Message : %s from server " , string);
        
        // dont forget to free the used memory
        free (string);
    }

    // close the connections and destroy the contexts
    zmq_close (requester);
    zmq_ctx_destroy (context);

    return 0;
}
```

### Reply Server ( rserver.c )

Here the `server` after recieving the message from the client, responds back to the `cient` witj `World` message.

```c
#include "zhelpers.h"

int main (void)
{
    void *context = zmq_ctx_new ();

    void *responder = zmq_socket (context, ZMQ_REP);
    zmq_connect (responder, "tcp://localhost:5000");

    // loop infinitely
    while (1)
    {
        // wait for next messages from client
        char *string = s_recv (responder);
        printf ("Recieved request : %s " , string);

        // simulation of communication delay
        sleep (1);

        s_send (responder, "World");
    }

    zmq_close (responder);
    zmq_ctx_close (context);

    return 0;
}
```