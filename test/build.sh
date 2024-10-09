gcc -E main.c -o main.i
gcc -S main.i -o main.s
gcc -c main.s -o main.o
gcc -E add.c -o add.i
gcc -S add.i -o add.s
gcc -c add.s -o add.o
gcc -E add_adv.c -o add_adv.i
gcc -S add_adv.i -o add_adv.s
gcc -c add_adv.s -o add_adv.o
gcc main.o add.o add_adv.o -o main.out
