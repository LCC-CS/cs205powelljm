PROGS = lab2a
CC = gcc
CFLAGS = -g  # Include debug symbols for GDB

# Build all programs
all: $(PROGS)

# Compile lab2a.c
lab2a: lab2a.c
	$(CC) $(CFLAGS) lab2a.c -o lab2a

# Run test
test: lab2a
	./lab2a 5

# Clean up
clean:
	rm -f *.o $(PROGS)

