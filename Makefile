CC = gcc
CFLAGS = -Wall -Wextra -O2

all: xmass-tree

xmass-tree: x-mass-tree.o
	$(CC) $(CFLAGS) -o xmass-tree main.o

x-mass-tree.o: x-mass-tree.c
	$(CC) $(CFLAGS) -c x-mass-tree.c

clean:
	rm -f xmass-tree *.o
