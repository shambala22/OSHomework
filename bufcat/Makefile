PATH_FLAGS = -I../lib -Wl,-rpath=../lib -L../lib

all:
	gcc -std=c99 $(PATH_FLAGS) bufcat.c -o bufcat -lbufio

clean:
	rm -f *.o
	rm -f bufcat

	


