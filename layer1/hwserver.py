import zmq

context = zmq.Context()

router = context.socket (zmq.ROUTER)

router.router_raw = True

router.bind ('tcp://*:5560')

while True:
    msg = router.recv_multipart()
    
    identity, request = msg

    print (identity)
    print (request)