import time
import zmq

context = zmq.Context()

print ("Connecting to Hello World server ...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

for i in range (0, 10):
    print ("Sending requests ...")
    socket.send(b"Hello")
    message = socket.recv()

    print ("Replied %s", message)