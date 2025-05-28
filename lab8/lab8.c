#include <stdio.h>
#include <stdint.h> // For fixed-size types like uint16_t and uint8_t

// Define a union to share memory between a 2-byte value and its bytes
union EndianCheck {
    uint16_t value;   // A 2-byte integer to hold a test pattern
    uint8_t bytes[2]; // Array of 2 bytes, sharing the same memory as 'value'
};

int main() {
    // Create a union variable to check endianness
    union EndianCheck check;

    // Set a test pattern: 0x1234 (2 bytes: 0x12 is high byte, 0x34 is low byte)
    check.value = 0x1234;

    // Check the first byte in memory to determine endianness
    // - Big-Endian: Stores 0x12 first (most significant byte)
    // - Little-Endian: Stores 0x34 first (least significant byte)
    if (check.bytes[0] == 0x12) {
        printf("Big-Endian\n"); // First byte is 0x12, so big-endian
    } else {
        printf("Little-Endian\n"); // First byte is 0x34, so little-endian
    }

    return 0; // Exit program
}
