#include <stdio.h>
#include <stdlib.h>

void print_binary(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if an argument is provided
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    // Convert the argument to an integer
    int number = atoi(argv[1]);

    // Print in decimal
    printf("Decimal: %d\n", number);
    
    // Print in octal
    printf("Octal: %o\n", number);
    
    // Print in hexadecimal
    printf("Hexadecimal: %x\n", number);
    
    // Print in binary
    printf("Binary: ");
    print_binary(number);

    return 0;
}
