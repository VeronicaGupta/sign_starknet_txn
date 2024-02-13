#ifndef __STARK256_H__
#define __STARK256_H__

#include <stdint.h>

#include "bip32.h"
#include "ecdsa.h"

extern const ecdsa_curve stark256;
extern const curve_info stark256_info;

int stark256_get_public_key(const ecdsa_curve *curve, uint8_t *priv_key, uint8_t *pub_key);

#endif