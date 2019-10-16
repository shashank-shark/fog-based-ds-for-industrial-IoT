import socket

HOST = "127.0.0.1"
PORT = 5560

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    print ("Connected to Server")
    s.sendall(b'Hello, world')
    data = s.recv(1024)