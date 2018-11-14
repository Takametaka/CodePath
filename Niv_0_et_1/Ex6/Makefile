run: main
	./main 100 100
	dot -Tpng tree.dot -o tree.png
	eog tree.png
	rm -f tree.data

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
	rm -f tree.png
	rm -f tree.data
	ls -l
