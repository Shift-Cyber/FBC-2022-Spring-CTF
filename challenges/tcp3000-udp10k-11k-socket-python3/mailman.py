#!/usr/bin/python3
from socket import *
from random import randint

sock_port = 3000
flag = None

# set flag from config
with open("flag.txt","r") as f:
    for l in f: flag = l.encode('ascii')

while True: # unfortunately cant use ynetd here cause we need to resolve source IP
    with socket(AF_INET, SOCK_STREAM) as sock_io:
        sock_io.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        sock_io.bind(('',sock_port))

        sock_io.listen()
        connection, (sender_address,sender_port) = sock_io.accept()
        print(f"Got connection from {sender_address}:TCP_{sender_port}")

        # Send challenge banner
        connection.send(b"Hey It's the mailman, I'll deliver the flag to you. I tend to get lost though so all I can gaurentee is that it will be delivered to you on a random UDP port between 5000 and 5500.\n\n> Press [enter] to continue")
        connection.recv(1024)

        with socket(AF_INET, SOCK_DGRAM) as sock_io_flag:
            random_port = randint(5000,5500)

            sock_io_flag.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            sock_io_flag.connect((sender_address,random_port))
            sock_io_flag.send(flag)

            print(f"Sent flag to {sender_address}:UDP_{random_port}")
            connection.send(b"\nIt was sent... somewhere...")        
        connection.close()
