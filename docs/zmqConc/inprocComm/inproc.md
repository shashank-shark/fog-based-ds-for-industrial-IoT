# Interprocess communication via `iproc`

When we start building multithreaded applications with ZeroMQ one of the important knowledge is to know how to coordinate between the threads in our application.

For this reason, ZeroMQ provides us with a `inproc` transport, which helps in achieving interprocess communication.

In the below program we attempt to create `three` threads which signal each other when they are ready.

## include `pthread.h` ( POSIX THREAD )

The syntax and attributes that `pthread` provides are : 

```c
int pthread_create(pthread_t *thread, pthread_attr_t *attr,
                   void *(*start_routine) (void *arg), void *arg);
```

## Program ( `inprocexample.c` )

`Note : ` A socket of type ZMQ_PAIR can only be connected to a single peer at any one time. No message routing or filtering is performed on messages sent over a ZMQ_PAIR socket.

Create a context
```c
void *context = zmq_ctx_new ();
```

Create a reciever
```c
void *reciever = zmq_socket (context, ZMQ_PAIR);
zmq_bind (reciever, "inproc://SHASHANK3");
```

Now create a thread and call the function `SHASHANK1`. The function body of `SHASHANK1` is written below.

```c
static void*
SHASHANK1 (void *context)
{
    void *xmitter = zmq_socket (context, ZMQ_PAIR);
    zmq_connect (xmitter, "inproc://SHASHANK2");

    printf ("SHASHANK1 is READY, signalling SHASHANK2\n");
    s_send (xmitter, "READY");

    zmq_close (xmitter);

    return NULL;
}
```

Now its time to call the function `SHASHANK2` using `pthread_create()` in main function.

```c
pthread_t thread;

// create thread and pass the context
pthread_create (&thread, NULL, SHASHANK2, context);
```

The body of function `SHASHANK2` is given below.

```c
static void*
SHASHANK2 (void *context)
{
    void *reciever = zmq_socket (context, ZMQ_PAIR);

    // first connect to inproc SHASHANK2
    zmq_bind (reciever, "inproc://SHASHANK2");

    // now again create a thread and call SHASHANK1
    pthread_t thread;
    pthread_create (&thread, NULL, SHASHANK1, context);

    // Now we wait for signal from SHASHANK1 and then send it to the s_recv() in main function
    char *string = s_recv (reciever);
    free (string);
    zmq_close (reciever);

    // Now signal to main function
    void *xmitter = zmq_socket (context, ZMQ_PAIR);
    zmq_connect (xmitter, "inproc://SHASHANK3");
    printf ("SHASHANK2 is READY, signalling main function\n");
    
    // signal
    s_send (xmitter, "READY");
    zmq_close (xmitter);

    return NULL;
}
```

In the main function we write code to recieve message from `SHASHANK2`.

```c
char *string = s_recv (reciever);
free (string);
zmq_close (reciever);
```