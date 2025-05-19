
PROGS = lab7b
CC = gcc

all: $(PROGS)

large_arrays: lab7b.c
	$(CC) lab7b.c -o lab7b

test: $(PROGS)
	./test.sh

clean:
	rm -f $(PROGS)
