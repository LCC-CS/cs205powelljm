PROGS = lab1a lab1b
CC = gcc

# Default target (build all programs)
all: $(PROGS)

# Compile lab1a.c into an executable
lab1a: lab1a.c
	$(CC) lab1a.c -o lab1a

# Assemble lab1b.asm into an object file
lab1b.o: lab1b.asm
	nasm -f elf64 lab1b.asm -o lab1b.o

# Link lab1b.o into an executable
lab1b: lab1b.o
	ld lab1b.o -o lab1b

# Run test programs
test: $(PROGS)
	@echo "Testing Hello CS205 in C"
	@./lab1a
	@echo "Testing Hello CS205 in Assembly"
	@./lab1b

# Clean up generated files
clean:
	rm -f *.o $(PROGS)

