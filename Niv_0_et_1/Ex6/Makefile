run: main
	./main
	dot -Tpng tree.dot -o tree.png
	eog tree.png

main: main.o tree.o
	gcc -Wall tree.o main.o -o main

main.o: main.c tree.h
	gcc -Wall -c main.c -o main.o

tree.o: tree.c tree.h
	gcc -Wall -c tree.c -o tree.o


clean: 
	rm -f *.o
	rm -f main
	rm -f tree.dot
