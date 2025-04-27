
PROGS = call_asm run_program fork_me network
CC = gcc

all: $(PROGS)

call_asm: call_asm.c
	$(CC) call_asm.c -o call_asm -masm=intel

fork_me: fork_me.c
	$(CC) fork_me.c -o fork_me

run_program: run_program.c
	$(CC) run_program.c -o run_program

network: network.c
	$(CC) network.c -o network

clean:
	rm -f $(PROGS)
