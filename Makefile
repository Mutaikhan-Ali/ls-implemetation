all: my_ls

my_ls: main.o set.o parse.o is.o get.o init.o sort.o string.o ls.o
	gcc main.o set.o parse.o is.o get.o init.o sort.o string.o ls.o -o my_ls

main.o: main.c
	gcc -c main.c
set.o: set.c
	gcc -c set.c
parse.o: parse.c
	gcc -c parse.c
get.o: get.c
	gcc -c get.c
is.o: is.c
	gcc -c is.c
init.o: init.c
	gcc -c init.c
ls.o: ls.c
	gcc -c ls.c
sort.o: sort.c
	gcc -c sort.c
string.o: string.c
	gcc -c string.c

clean:
	rm a.out *.o my_ls