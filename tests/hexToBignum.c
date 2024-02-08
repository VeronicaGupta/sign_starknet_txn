#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Define the size of the bignum256 array
#define NUM_WORDS 9

typedef struct {
    uint32_t words[NUM_WORDS];
} bignum256;

void hex_to_bignum(const char *hex_str, bignum256 *result) {
    // Length of the hex string
    size_t len = strlen(hex_str);
    
    // Start from the end of the string
    const char *ptr = hex_str + len - 8;  // Each word is represented by 8 hex characters
    
    // Initialize the result array to zero
    memset(result, 0, sizeof(bignum256));

    // Loop through each word of the bignum256 in reverse order
    for (int i = NUM_WORDS - 1; i >= 0 && ptr >= hex_str; i--) {
        // Convert the current word from hex to integer
        sscanf(ptr, "%8x", &result->words[i]);

        // Move to the next word in the hex string
        ptr -= 8;
    }
}

// Function to print a bignum256
void print_bignum(const bignum256 *num) {
    printf("bignum{");
    for (int i = 0; i < NUM_WORDS - 1; i++) {
        printf("0x%08x, ", num->words[i]);
    }
    printf("0x%08x}\n", num->words[NUM_WORDS - 1]);
}

int main() {
    const char *hex_str = "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f";
    bignum256 result;
    hex_to_bignum(hex_str, &result);
    print_bignum(&result);
    return 0;
}
