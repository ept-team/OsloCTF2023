from pwn import *

context.arch = 'amd64'

shellcode = """
mov rax, 60
mov rdi, 1337
syscall

"""

e = ELF.from_assembly(shellcode)
e.save('shellcode.elf')

e.debug().interactive()