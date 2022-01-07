#!/usr/bin/python3
from pwn import *

io = remote('battleground.ctf.scyca.org',1234)

for i in range(100):
    io.recvuntil(b": ")
    io.sendline(f"{i}".encode('ascii'))

print(io.recv().decode())

