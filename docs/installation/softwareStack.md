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

##  **CZMQ**

**High-level C binding for ØMQ**

Note that libzmq is a dependency of czmq.

```shell
$ git clone git://github.com/zeromq/czmq.git
```
```shell
$ cd czmq
```
```shell
$ ./autogen.sh
```
```shell
$ ./configure
```
```shell
$ make check
```
```shell
$ sudo make install
```
```shell
$ sudo ldconfig
```
```shell
$ cd ..
```

##  **RabbitMQ**

RabbitMQ is an open-source message-broker software that originally implemented the Advanced Message Queuing Protocol and has since been extended with a plug-in architecture to support Streaming Text Oriented Messaging Protocol, Message Queuing Telemetry Transport, and other protocols.

**#1 Add RabbitMQ Repository to Ubuntu**

```shell
$ wget -O- https://dl.bintray.com/rabbitmq/Keys/rabbitmq-release-signing-key.asc | sudo apt-key add -
```
```shell
$ wget -O- https://www.rabbitmq.com/rabbitmq-release-signing-key.asc | sudo apt-key add -
```
```shell
$ echo "deb https://dl.bintray.com/rabbitmq/debian $(lsb_release -sc) main" | sudo tee /etc/apt/sources.list.d/rabbitmq.list
```

**#2 Installing RabbitMQ server on Ubuntu**

```shell
$ sudo apt-get update
```
```shell
$ sudo apt -y install rabbitmq-server
```

**#3 Control and Manage Services**

```shell
$ sudo systemctl status  rabbitmq-server.service 
```

You can confirm if the service is configured to start on boot using the command:

```shell
$  systemctl is-enabled rabbitmq-server.service 
```
If it returns disabled, enable it by running:

```shell
$ sudo systemctl enable rabbitmq-server
```

**#4  Enable the RabbitMQ Management Dashboard**

```shell
$ sudo rabbitmq-plugins enable rabbitmq_management
```
The Web service should be listening on TCP port 15672

```shell
# ss -tunelp | grep 15672
```
```shell
$ sudo ufw allow proto tcp from any to any port 5672,15672
```

RabbitMQ dashboard will be running on `https://localhost:15672` on your system.


