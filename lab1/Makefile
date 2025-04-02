
PROGS = lab1a lab1b
CC = gcc


# Telling it to make all the programs
all: $(PROGS)

# Instructions to Compile lab1a.c
lab1a: lab1a.c
	$(CC) lab1a.c -o lab1a

# Instructions to assemble lab1b.asm
lab1b.o: lab1b.asm
	nasm -f elf64 lab1b.asm -o lab1b.o

# Instructions to link lab1b.o
lab1b: lab1b.o
	ld lab1b.o -o lab1b

# A test option
test: $(PROGS)
	echo "Testing Hello CS205 in C"
	./lab1a
	echo "Testing Hello CS205 in Assembly"
	./lab1b

# Instructions to remove the files
clean:
	rm -f *.o $(PROGS)
