CC = gcc
CFLAGS = -Wall -Wextra -O2

all: xmass-tree

mytool: main.o
	$(CC) $(CFLAGS) -o xmass-tree main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f xmass-tree *.o
