#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bignum.h"

uint8_t* hexToUint8(const char *hexString);
void uint8ToHexString(const uint8_t *data, size_t size, char* hexstring);
char* intToHex(int value);
char* print_arr(char* name, uint8_t* bytearray, size_t size);
uint8_t* print_hexarr(char* name, const char *hexString, size_t size, uint8_t* bytearray);
void print_bignum(char* name, const bignum256 *obj_bn);
void bn_check_hex (char *obj_hex_org, bignum256 obj_bn_org);

static bool debug = true;


#endif