# Software Stack

##  **ZeroMQ**
ZeroMQ (also known as ØMQ, 0MQ, or zmq) looks like an embeddable networking library but acts like a concurrency framework. It gives you sockets that carry atomic messages across various transports like in-process, inter-process, TCP, and multicast. You can connect sockets N-to-N with patterns like fan-out, pub-sub, task distribution, and request-reply. It's fast enough to be the fabric for clustered products. Its asynchronous I/O model gives you scalable multicore applications, built as asynchronous message-processing tasks. It has a score of language APIs and runs on most operating systems.

### Installing zmq
We can install zmq in two ways on any linux distribution

1. Using linux package managers
    * For Debian based systems the default package managers are :  `apt`, `apt-get`
    * For Red Hat based systems the default package managers are  : `yum`, `dnf`
    * Just use the command `sudo dnf install zeromq-devel` for Red-Hat based systems.
    * Just use the command `sudo apt install zeromq3-devel` for debian based systems.

2. Building from source (my recommended way)

First install the necessary dependencies

```sh
$ sudo apt-get update
```
```sh
$ sudo apt-get install -y git build-essential
```
```sh
$ sudo apt-get install -y libtool pkg-config
```
```sh
$ sudo apt-get install -y autotools-dev autoconf automake cmake
```
```sh
$ sudo apt-get install -y uuid-dev libpcre3-dev
```
```sh
$ sudo apt-get install -y libsodium-dev valgrind
```

Build libzmq from source

```sh
$ git clone git://github.com/zeromq/libzmq.git
```
```sh
$ cd libzmq
```
```sh
$ ./autogen.sh
```
```sh
$ ./configure
```
```sh
$ make check
```
```sh
$ sudo make install
```
```sh
$ sudo ldconfig
```
```sh
$ cd ..
```
