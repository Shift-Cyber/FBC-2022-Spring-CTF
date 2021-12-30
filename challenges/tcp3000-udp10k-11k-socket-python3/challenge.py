#!/usr/bin/python3
from socket import *
from random import randint

sock_host = '127.0.0.1'
sock_port = 1234
flag = b"FBC{connection?_less_connection...connection-less}"

while True: #unfortunately cant use ynetd here cause we need to resolve source IP
    with socket(AF_INET, SOCK_STREAM) as sock_io:
        sock_io.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        sock_io.bind((sock_host,sock_port))

        sock_io.listen()
        connection, (sender_address,sender_port) = sock_io.accept()
        print(f"Got connection from {sender_address}:TCP_{sender_port}")

        # Send challenge banner
        connection.send(b"Hey It's the mailman, I'll deliver the flag to you. I tend to get lost though so all I can gaurentee is that it will be delivered to you on a random UDP port between 50000 and 55000.\n\n> Press [enter] to continue")
        connection.recv(1024)

        with socket(AF_INET, SOCK_DGRAM) as sock_io_flag:
            random_port = randint(50000,55000)

            sock_io_flag.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            sock_io_flag.connect((sender_address,random_port))
            sock_io_flag.send(flag)

            print(f"Sent flag to {sender_address}:UDP_{random_port}")
            connection.send(b"\nIt was sent... somewhere...")        
        connection.close()
    
    

"""
with connection:
    connection.send("Welcome to the server")

except OSError:
    print(f"[!] Couldn't bind the socket on TCP_{sock_port}")
    exit()"""