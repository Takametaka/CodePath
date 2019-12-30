CC=gcc
CFLAGS=-Wall -Werror -Wextra

run: main
	./$< tree.data
	dot -Tpng tree.dot -o tree.png
	feh tree.png

main: main.c
	$(CC) $(CFLAGS) $< -o $@ 


clean: 
	rm -f *.o
	rm -f main
	rm -f tree.dot
	rm -f tree.png

edit:
	vim -p Makefile main.c tree.data
