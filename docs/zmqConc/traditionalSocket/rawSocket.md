# Using ZMQ_ROUTER_RAW option to achieve communication between ZMQ and non-ZMQ applications.

The option `ZMQ_ROUTER_RAW` sets the raw mode on the `ROUTER`, when set to 1.
When the `ROUTER` socket is in raw mode, and when using the `tcp://` transport, it will read and write TCP data without ØMQ framing. This lets ØMQ applications talk to non-ØMQ applications.

The below figure shows how this is achieved by setting the `ZMQ_ROUTER_RAW` to `1` in `setsockopt`.

![Raw Router](./rawRouter.png)


So, even if the client uses different protocols our project will be able to recieve the raw messages and we will be able to process the requests of all the client devices connected to our `broker / server`.

## [ UPDATE ]
From ZeroMQ v4 the support for `ZMQ_ROUTER_RAW` is taken down, instead the use of `ZMQ_STREAM` can be used.

The below program shows the usage of `ZMQ_STREAM`.

