#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t val[9];
} bignum256;

void bignum256_to_hex(const bignum256 *num) {
    for (int i = 8; i >= 0; i--) {
        printf("%08x", num->val[i]);
    }
    printf("\n");
}

int main() {
    bignum256 num = {
        .val = {0x1ffffc2f, 0x1ffffff7, 0x1fffffff, 0x1fffffff,
                0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff,
                0xffffff}
    };

    bignum256_to_hex(&num);

    return 0;
}