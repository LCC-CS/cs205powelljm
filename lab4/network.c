#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 16

// Converts an IP string to a 32-bit unsigned integer.
unsigned int ip_str2num(char *ipaddr) {
    char ipcopy[LEN];
    strncpy(ipcopy, ipaddr, LEN - 1);
    ipcopy[LEN - 1] = '\0'; // Ensure null-termination
    unsigned int value = 0;
    unsigned int octet;
    char *current = strtok(ipcopy, ".");
    if (!current) return 0; // Invalid IP
    value = atoi(current); // First octet
    for (int i = 0; i < 3; i++) {
        current = strtok(NULL, ".");
        if (!current) return 0; // Incomplete IP
        octet = atoi(current);
        value *= 256;
        value += octet;
    }
    return value;
}

// Converts a 32-bit unsigned integer to an IP string.
void ip_num2str(unsigned int num, char *ipaddr) {
    unsigned int octet[4];
    for (int i = 3; i >= 0; i--) {
        octet[i] = num % 256;
        num = num / 256;
    }
    sprintf(ipaddr, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);
}

// Function to convert CIDR notation to subnet mask
unsigned int cidr_to_subnet_mask(int cidr) {
    unsigned int mask = 0xFFFFFFFF;
    mask = mask << (32 - cidr);
    return mask;
}

// Function to calculate the subnet address
unsigned int subnet_address(unsigned int ip, unsigned int subnet_mask) {
    return ip & subnet_mask;
}

// Function to calculate the subnet broadcast
unsigned int subnet_broadcast(unsigned int ip, unsigned int subnet_mask) {
    return ip | ~subnet_mask;
}

// Function to calculate the first host (subnet address + 1)
unsigned int first_host(unsigned int subnet) {
    return subnet + 1;
}

// Function to calculate the last host (subnet broadcast - 1)
unsigned int last_host(unsigned int broadcast) {
    return broadcast - 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <CIDR subnet mask>\n", argv[0]);
        return 1;
    }

    char ipaddr[LEN];
    strncpy(ipaddr, argv[1], LEN - 1);
    ipaddr[LEN - 1] = '\0'; // Ensure null-termination
    int cidr = atoi(argv[2]);

    if (cidr < 0 || cidr > 32) {
        fprintf(stderr, "Invalid CIDR value. Must be between 0 and 32.\n");
        return 1;
    }

    // Convert the IP address to an integer value
    unsigned int ipvalue = ip_str2num(ipaddr);
    if (ipvalue == 0) {
        fprintf(stderr, "Invalid IP address: %s\n", ipaddr);
        return 1;
    }

    // Convert the CIDR value to a subnet mask
    unsigned int subnet_mask = cidr_to_subnet_mask(cidr);

    // Calculate the subnet address and broadcast
    unsigned int subnet_addr = subnet_address(ipvalue, subnet_mask);
    unsigned int broadcast = subnet_broadcast(ipvalue, subnet_mask);
    unsigned int first_host_val = first_host(subnet_addr);
    unsigned int last_host_val = last_host(broadcast);

    // Convert the calculated values back to IP format for display
    char subnet_str[LEN], first_host_str[LEN], last_host_str[LEN], broadcast_str[LEN];
    ip_num2str(subnet_addr, subnet_str);
    ip_num2str(first_host_val, first_host_str);
    ip_num2str(last_host_val, last_host_str);
    ip_num2str(broadcast, broadcast_str);

    // Display the results
    printf("IP Address      = %s\n", ipaddr);
    printf("CIDR Mask       = /%d\n", cidr);
    printf("Subnet Address  = %s\n", subnet_str);
    printf("First Host      = %s\n", first_host_str);
    printf("Last Host       = %s\n", last_host_str);
    printf("Subnet Broadcast= %s\n", broadcast_str);

    return 0;
}

