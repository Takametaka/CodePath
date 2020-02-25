CC=gcc
CFLAGS=-Wall -Werror -Wextra

run: ex9.out
	./$< "9+0/6*(5+6+8+6/2)"
	#valgrind ./$< "9+0/6*(5+6+8+6/2)"

ex9.out: ex9.c list.o
	$(CC) $(CFLAGS) $< -o $@ list.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $< -o $@


edit:
	vim -p Makefile ex9.c list.h list.c
