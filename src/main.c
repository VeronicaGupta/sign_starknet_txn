#include "utility.h"
#include "address.h"

int main() {
    // *****************starknet g testnet details**********************//

    const size_t seed_len = 64;
    size_t pubkey_len = 32;
    const size_t privkey_len = 32;
    const size_t addr_len = 32;

    uint8_t seed[seed_len];
    uint8_t public_key[pubkey_len];
    uint8_t private_key[privkey_len];
    uint8_t address[addr_len];
    HDNode node;    

    // get seed for eth 
    // const char* mnemonic = "spread sword village control response joke phrase share merit miss door canoe setup surge remind tiger increase sphere busy hand scrap diesel hair bomb";
    // const char* passphrase = "";
    // pubkey_len = 33; // uncompressed

    // get stark seed from bip39 (24 words) 
    const char* mnemonic = "road donate inch warm beyond sea wink shoot fashion gain put vocal";
    const char* passphrase = "";

    get_seed(mnemonic, passphrase, seed);

    // Constants for HD path
    #define PURPOSE     0x8000002C  // 44
    #define COIN_TYPE   0x8000003C  // 60 Ethereum
    #define ACCOUNT     0x80000000 
    #define CHANGE      0x00000000
    #define ADDRESS_IDX 0x00000000

    memzero(seed, seed_len);
    memzero(public_key, pubkey_len);
    memzero(private_key, privkey_len);
    memzero(address, addr_len);


    printf("\nPATH=m/40'/60'/0'/0/0\n");
    get_keys(seed, seed_len, PURPOSE, COIN_TYPE, ACCOUNT, CHANGE, ADDRESS_IDX, node);

    // Constants for HD path m / purpose' / coin_type' / account' / change / address_index
    #define PURPOSE     0x8000002C  // 44
    #define COIN_TYPE   0x8000232C  // 9004 Starknet
    #define ACCOUNT     0x80000000
    #define CHANGE      0x00000000
    #define ADDRESS_IDX 0x00000000

    memzero(seed, seed_len);
    memzero(public_key, pubkey_len);
    memzero(private_key, privkey_len);
    memzero(address, addr_len);

    printf("\nPATH=m/40'/9004'/0'/0/0\n");
    print_arr("1122", &node.private_key, privkey_len);
    get_keys(&node.private_key[0], privkey_len, PURPOSE, COIN_TYPE, ACCOUNT, CHANGE, ADDRESS_IDX, node);

    // ***************when coins in account****************************//

    // when unsigned txn hex is available
    // const char *unsigned_txn_hex = "ef03850c9f71f523826349946b61fd05fa7e73c2de6b1999a390fee25210907287470de4df820000818083aa36a78080";
    // printf("\nunsigned txn[%d bytes] : %s\n", strlen(unsigned_txn_hex)/2, unsigned_txn_hex);
    // size_t unsigned_txn_len = strlen(unsigned_txn_hex) / 2;
    // uint8_t unsigned_txn[unsigned_txn_len]; 
    // print_hexarr("unsigned txn", unsigned_txn_hex, unsigned_txn_len, unsigned_txn);

    // // when unsigned txn details are available
    // uint8_t unsigned_txn[200];
    // int unsigned_txn_len = generate_unsigned_txn(public_key, pubkey_len, unsigned_txn);
    // print_arr("unsigned txn", unsigned_txn, unsigned_txn_len);

    // uint8_t unsigned_txn_hash[SHA3_256_DIGEST_LENGTH];
    // // keccak_256(unsigned_txn, unsigned_txn_len, unsigned_txn_hash);
    // hash256(unsigned_txn, unsigned_txn_hash, unsigned_txn_len);
    // print_arr("unsigned txn hash", unsigned_txn_hash, SHA3_256_DIGEST_LENGTH);

    // // Sign the hash with the private key
    // int sig_len = privkey_len*2;
    // uint8_t sig[sig_len];
    // int recid=0;
    // ecdsa_sign_digest(&secp256k1, private_key, unsigned_txn_hash, sig, &recid, 0);
    // print_arr("sig", sig, sig_len);

    // // Check the signature with public key
    // int result = ecdsa_verify_digest(&secp256k1, public_key,  sig, unsigned_txn_hash);
    // if (result == 0) {
    //     printf("Transaction signing successful.\n");
    // } else {
    //     fprintf(stderr, "Error: Transaction signing failed at %d.\n", result);
    // }

    // // Output the values
    // uint32_t v=0;
    // uint8_t r[privkey_len], s[privkey_len];
    // v = generate_vrs(sig, recid, v, r, s, sig_len);

    // printf("r_id: %d\n", recid);
    // printf("v: %02x\n", v);
    // print_arr("r", r, 32);
    // print_arr("s", s, 32);

    // uint8_t signed_txn[120];
    // generate_signed_txn(unsigned_txn, v, r, s, unsigned_txn_len, signed_txn);

    // print_hexarr("public key", "032a382eb01b1558e75a35fb44ca48223b48ca05029b5690219cb057ab5d188d", 32, public_key);

    // // get uncompressed public key from the original seed
    // const int pubkey_uncompressed_len = 65;
    // uint8_t pubkey_uncompressed[pubkey_uncompressed_len];
    // print_arr("m4460000 public key", public_key, pubkey_len);
    // ecdsa_uncompress_pubkey(&secp256k1, public_key, pubkey_uncompressed);
    // print_arr("m4460000 uncom public key", pubkey_uncompressed, pubkey_uncompressed_len);

    // // // verify public key from sig and digest
    // // memzero(pubkey_uncompressed, pubkey_uncompressed_len);
    // // ecdsa_recover_pub_from_sig(&secp256k1, pubkey_uncompressed, sig, unsigned_txn_hash, recid);
    // // print_arr("derived uncom public key", pubkey_uncompressed, pubkey_uncompressed_len);

    // // verify address from the derived public key
    // uint8_t pubkey_hash[SHA3_256_DIGEST_LENGTH];
    // keccak_256(&pubkey_uncompressed[1], pubkey_uncompressed_len-1, pubkey_hash);

    // const int ethereum_address_len = 64;
    // char ethereum_address[ethereum_address_len];
    // memzero(ethereum_address, ethereum_address_len);       
    // ethereum_address_checksum(&pubkey_hash[12], ethereum_address, false, 1);

    // print_arr("derived uncom pubkey hash", pubkey_hash, SHA3_256_DIGEST_LENGTH);
    // printf("\nderived m4460000 addr[%d bytes]: %s\n",ethereum_address_len,  ethereum_address);

    // curve_parameters();
    
    return 0;
}