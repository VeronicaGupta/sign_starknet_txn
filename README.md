# Sign & Broadcast ETH TXN Locally

## Dependency
Add trezor-crypto library in include folder

## Execute
valgrind ./run.sh --leak-check=full

## Broadcast Signed Txn:
https://sepolia.etherscan.io/pushTx 

## Check Current Broadcasted Signed Txn (Sepolia Testnet Legacy Ethereum Transaction)
https://sepolia.etherscan.io/tx/0x32e8803f66ccb31e5274c0d715d82fd9d62d3fbaa762dfeff3407b9051c49e3b

## Trezor-crypt library changes
For 'trezor-firmware' (branch release/23.12). Add below in rand.c:

### rand.h:
#### Add
```
#define USE_INSECURE_PRNG
```

### address.h:
#### Add
```
#define USE_ETHEREUM true
```

###  secp256k1.c
#### Replace
```
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
```
