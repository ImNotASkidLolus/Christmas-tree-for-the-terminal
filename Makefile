CC = gcc
CFLAGS = -Wall -Wextra -O2

BIN = xmass-tree

all: $(BIN)

$(BIN): x-mass-tree.o
	$(CC) $(CFLAGS) -o $(BIN) x-mass-tree.o

x-mass-tree.o: x-mass-tree.c
	$(CC) $(CFLAGS) -c x-mass-tree.c

install: $(BIN)
	install -m 755 $(BIN) /usr/local/bin/$(BIN)

clean:
	rm -f $(BIN) *.o
