COME COMPILARE ED ESEGUIRE FILE ASSEMBLY

FILE: hello.s

as -o hello.o hello.s

ld -o hello hello.o

ld -o hello.x hello.o
