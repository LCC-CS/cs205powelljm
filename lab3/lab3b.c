#include <stdio.h>
#include <stdlib.h>

// Function to print an integer in binary for a specified number of bits
void print_binary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if an argument is provided
    if (argc != 2) {
        printf("Usage: %s <floating-point number>\n", argv[0]);
        return 1;
    }

    // Convert the argument to a float
    float f = atof(argv[1]);

    // Reinterpret the float's bits as an unsigned int
    unsigned int i = *(unsigned int *)&f;

    // Extract sign bit (bit 31)
    unsigned int sign = (i >> 31) & 1;

    // Extract exponent (bits 30–23)
    unsigned int exponent = (i >> 23) & 0xFF; // 0xFF = 11111111 (8 bits)

    // Extract mantissa (bits 22–0)
    unsigned int mantissa = i & 0x7FFFFF; // 0x7FFFFF = 01111111111111111111111 (23 bits)

    // Print the components in binary
    printf("Sign bit: ");
    print_binary(sign, 1); // 1 bit

    printf("Exponent: ");
    print_binary(exponent, 8); // 8 bits

    printf("Mantissa: ");
    print_binary(mantissa, 23); // 23 bits

    return 0;
}
