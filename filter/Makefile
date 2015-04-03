PATH_FLAGS = -I../lib -Wl,-rpath=../lib -L../lib
all: filter
clean:
	rm -f *.o
	rm -f filter
filter: filter.c
	gcc -g -std=c99 $(PATH_FLAGS) filter.c -o filter -lhelpers
