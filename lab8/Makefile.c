PROGS = lab8
CC = gcc

all: $(PROGS)

lab8: lab8.c
	$(CC) lab8.c -o lab8

test: $(PROGS)
	./test.sh

clean:
	rm -f $(PROGS)
