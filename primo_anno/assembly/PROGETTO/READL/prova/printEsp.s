.section .data
output:
    .ascii "The stack pointer (ESP) is: 0x%08x\n"

.section .text
.global printEsp
.type printEsp, @function

printEsp:
    movl $4, %eax        # system call number (sys_write)
    movl $1, %ebx        # file descriptor (stdout)
    pushl %esp           # push ESP
    popl %ecx            # pop into ECX
    pushl %ecx           # push ECX (ESP value)
    leal output, %ecx    # load address of output string
    pushl %ecx           # push address of output string
    movl $29, %edx       # length of output string
    int $0x80            # call kernel


