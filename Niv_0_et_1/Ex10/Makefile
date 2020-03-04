CC=gcc
CFLAGS=-Wall -Werror -Wextra

run: ex10.out
	#./$< 2732 -0.724 0.19 500.0
	#./$< 2732 -0.724 0.19 10.0
	#./$< 4000 -0.5 0.0 1.0
	./$< 1000 -0.5 0.0 1.0
	feh --force-aliasing mandelbrot_set.ppm

ex10.out: ex10.c 
	$(CC) $(CFLAGS) $< -o $@ -lm

edit:
	vim -p Makefile ex10.c
