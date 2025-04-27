#include <stdio.h>
#include <stdlib.h>

// Function to convert a number to a binary string
void to_binary(unsigned int num, char *bin_str) {
    for (int i = 31; i >= 0; i--) {
        bin_str[31 - i] = (num & (1 << i)) ? '1' : '0';
    }
    bin_str[32] = '\0'; // Null-terminate the string
}

// Assembly function for bitwise AND
unsigned int bitwise_and(unsigned int a, unsigned int b) {
    unsigned int result;
    __asm__ __volatile__ (
        "mov %0, %1\n\t"    // Move a into result
        "and %0, %2\n\t"    // AND result with b
        : "=r" (result)     // Output: result in a register
        : "r" (a), "r" (b)  // Inputs: a and b in registers
        :                   // No clobbered registers needed
    );
    return result;
}

// Assembly function for bitwise OR
unsigned int bitwise_or(unsigned int a, unsigned int b) {
    unsigned int result;
    __asm__ __volatile__ (
        "mov %0, %1\n\t"    // Move a into result
        "or %0, %2\n\t"     // OR result with b
        : "=r" (result)     // Output: result in a register
        : "r" (a), "r" (b)  // Inputs: a and b in registers
        :                   // No clobbered registers needed
    );
    return result;
}

// Assembly function for bitwise XOR
unsigned int bitwise_xor(unsigned int a, unsigned int b) {
    unsigned int result;
    __asm__ __volatile__ (
        "mov %0, %1\n\t"    // Move a into result
        "xor %0, %2\n\t"    // XOR result with b
        : "=r" (result)     // Output: result in a register
        : "r" (a), "r" (b)  // Inputs: a and b in registers
        :                   // No clobbered registers needed
    );
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    unsigned int num1 = atoi(argv[1]);
    unsigned int num2 = atoi(argv[2]);

    unsigned int and_result = bitwise_and(num1, num2);
    unsigned int or_result = bitwise_or(num1, num2);
    unsigned int xor_result = bitwise_xor(num1, num2);

    // Convert results to binary strings
    char bin1[33], bin2[33], bin_and[33], bin_or[33], bin_xor[33];
    to_binary(num1, bin1);
    to_binary(num2, bin2);
    to_binary(and_result, bin_and);
    to_binary(or_result, bin_or);
    to_binary(xor_result, bin_xor);

    // Print the results
    printf("%s AND %s = %s\n", bin1, bin2, bin_and);
    printf("%s OR %s = %s\n", bin1, bin2, bin_or);
    printf("%s XOR %s = %s\n", bin1, bin2, bin_xor);

    return 0;
}

