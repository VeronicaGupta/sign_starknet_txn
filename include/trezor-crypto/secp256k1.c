/**
 * Copyright (c) 2013-2014 Tomas Dzetkulic
 * Copyright (c) 2013-2014 Pavol Rusnak
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "secp256k1.h"

const ecdsa_curve secp256k1 = {
    /* .prime */ {/*.val =*/{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00440000, 0x00000000, 0x080000}},

    /* G */
    {/*.x =*/{/*.val =*/{0x0943cfca, 0x0b91ec5e, 0x0606780f, 0x19fb361a, 0x0f0c7dea, 0x16a0ad20, 0x1c6defb3, 0x1830b332, 0x01ef15}},
     /*.y =*/{/*.val =*/{0x16e8dc1f, 0x03980061, 0x0f90e8ca, 0x07d9a235, 0x0ec62de5, 0x0400efa3, 0x1cc2def9, 0x00c15492, 0x005668}}},

    /* order */
    {/*.val =*/{0x0dc64d2f, 0x1335120d, 0x19ec8c87, 0x0224db95, 0x1ffffb78, 0x1fffffff, 0x0043ffff, 0x00000000, 0x080000}},

    /* order_half */
    {/*.val =*/{0x0a1c688d, 0x010d9f8f, 0x13982e58, 0x19ec9a29, 0x1babb509, 0x15a67bc5, 0x19baebc2, 0x0f84666e, 0x07d9e5}},

    /* a */ 1,

    /* b */ {/*.val =*/{0x1cee9e89, 0x066fe5cc, 0x1245707d, 0x15a4d82b, 0x1a8c5609, 0x0cb6b97b, 0x03785439, 0x027df7c8, 0x06f214}}

#if USE_PRECOMPUTED_CP
    ,
    /* cp */
    {
#include "secp256k1.table"
    }
#endif
};

const curve_info secp256k1_info = {
    .bip32_name = "Bitcoin seed",
    .params = &secp256k1,
    .hasher_base58 = HASHER_SHA2D,
    .hasher_sign = HASHER_SHA2D,
    .hasher_pubkey = HASHER_SHA2_RIPEMD,
    .hasher_script = HASHER_SHA2,
};

const curve_info secp256k1_decred_info = {
    .bip32_name = "Bitcoin seed",
    .params = &secp256k1,
    .hasher_base58 = HASHER_BLAKED,
    .hasher_sign = HASHER_BLAKE,
    .hasher_pubkey = HASHER_BLAKE_RIPEMD,
    .hasher_script = HASHER_BLAKE,
};

const curve_info secp256k1_groestl_info = {
    .bip32_name = "Bitcoin seed",
    .params = &secp256k1,
    .hasher_base58 = HASHER_GROESTLD_TRUNC,
    .hasher_sign = HASHER_SHA2,
    .hasher_pubkey = HASHER_SHA2_RIPEMD,
    .hasher_script = HASHER_SHA2,
};

const curve_info secp256k1_smart_info = {
    .bip32_name = "Bitcoin seed",
    .params = &secp256k1,
    .hasher_base58 = HASHER_SHA3K,
    .hasher_sign = HASHER_SHA2,
    .hasher_pubkey = HASHER_SHA2_RIPEMD,
    .hasher_script = HASHER_SHA2,
};
