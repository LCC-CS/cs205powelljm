PROGS = lab3a
CC = gcc
CFLAGS = -g  # Include debug symbols for GDB

# Build all programs
all: $(PROGS)

# Compile lab3b.c
lab2a: lab3b.c
	$(CC) $(CFLAGS) lab3b.c -o lab3b

# Run test
test: lab3b
	./lab3b 5

# Clean up
clean:
      	rm -f *.o $(PROGS)

