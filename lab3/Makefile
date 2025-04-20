PROGS = lab3a
CC = gcc
CFLAGS = -g  # Include debug symbols for GDB

# Build all programs
all: $(PROGS)

# Compile lab3a.c
lab2a: lab3a.c
	$(CC) $(CFLAGS) lab3a.c -o lab3a

# Run test
test: lab3a
	./lab3a 5

# Clean up
clean:
      	rm -f *.o $(PROGS)

