CC=gcc
CFLAGS=-Wall -Werror -Wextra

run: main
	./$< 100 100
	dot -Tpng tree.dot -o tree.png
	eog tree.png
	rm -f tree.data

main: main.o tree.o
	gcc -Wall $^ -o $@

main.o: main.c tree.h
	gcc -Wall -c $< -o $@ 

tree.o: tree.c tree.h
	gcc -Wall -c $< -o $@


clean: 
	rm -f *.o
	rm -f main
	rm -f tree.dot
	rm -f tree.png
	rm -f tree.data

edit:
	vim -p Makefile main.c tree.h tree.c
