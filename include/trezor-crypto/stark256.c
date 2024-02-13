#include "stark256.h"

const ecdsa_curve stark256 = {
    /* .prime */ {/*.val =*/{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00440000, 0x00000000, 0x080000}},

    /* G */
    {/*.x =*/{/*.val =*/{0x0943cfca, 0x0b91ec5e, 0x0606780f, 0x19fb361a, 0x0f0c7dea, 0x16a0ad20, 0x1c6defb3, 0x1830b332, 0x01ef15}},
     /*.y =*/{/*.val =*/{0x16e8dc1f, 0x03980061, 0x0f90e8ca, 0x07d9a235, 0x0ec62de5, 0x0400efa3, 0x1cc2def9, 0x00c15492, 0x005668}}},

    /* order */
    {/*.val =*/{0x0dc64d2f, 0x1335120d, 0x19ec8c87, 0x0224db95, 0x1ffffb78, 0x1fffffff, 0x0043ffff, 0x00000000, 0x080000}},

    /* order_half */
    {/*.val =*/{0x0a1c688d, 0x010d9f8f, 0x13982e58, 0x19ec9a29, 0x1babb509, 0x15a67bc5, 0x19baebc2, 0x0f84666e, 0x07d9e5}},

    /* a */ 1,

    /* b */ 
    {/*.val =*/{0x1cee9e89, 0x066fe5cc, 0x1245707d, 0x15a4d82b, 0x1a8c5609, 0x0cb6b97b, 0x03785439, 0x027df7c8, 0x06f214}}
};

const curve_info stark256_info = {
    .bip32_name = "Starknet seed",
    .params = &stark256,
    .hasher_base58 = HASHER_SHA2D,
    .hasher_sign = HASHER_SHA2D,
    .hasher_pubkey = HASHER_SHA2_RIPEMD,
    .hasher_script = HASHER_SHA2,
};

int stark256_get_public_key(const ecdsa_curve *curve, uint8_t *priv_key, uint8_t *pub_key){
    curve_point R = {0};
    bignum256 k = {0};

    bn_read_be(priv_key, &k);
    if (bn_is_zero(&k) || !bn_is_less(&k, &curve->order)) {
    // Invalid private key.
    memzero(pub_key, 33);
    return -1;
    }

    // compute k*G
    if (scalar_multiply(curve, &k, &R) != 0) {
    memzero(&k, sizeof(k));
    return 1;
    }

    pub_key[0] = 0x02 | (R.y.val[0] & 0x01);
    bn_write_be(&R.x, pub_key + 1);
    memzero(&R, sizeof(R));
    memzero(&k, sizeof(k));
    return 0;
}