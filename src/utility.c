#include "utility.h"

const char* hash = "9447bd9c4b781d2aa4733461f3062ed08bee88e83ea81a80899bf19af274e12d";
const char* vseed = "2990a761daa2249c91ae98acf56ecf558876f6aa566e1e6e025996f12c830b793d87dde3f68cf9138fbe041bb75ba500c8eadee43d3ce2c95f84f89925bf8db5";
const char* m_pubkey = "036cd519b8ee267e7135b44e802df07970e56e3447bec20b720bd8fd8217b35a1d";
const char* m_chaincode = "10f33e10df2f3864bb74e671cd510804cb69b88ae570fb714b4506ccca813b5c";
const char* m44_pubkey = "03934580d6dc070772788b0c9d31c091596cd7ed06a92dcaa94d5029c83984cd7c";
const char* m4460_pubkey = "027dc18d1ef4cdac075436ccc8ed4e9811d33d82f56a4c371854b28817af57c76a";
const char* m44600_pubkey = "0298923deeecc9350aac6675e3f296bc5b37c35c34e8162c610c54ce2a6627af15";
const char* m446000_pubkey = "02ea988cd5d2bfbc11dd37a882565517aa2fa45a0c4dc4bff5cc8b727acd63a73a";
const char* m4460000_pubkey = "024eb7a0fb5db32746a28adf81a24daa5312d351c5af8ee957d04c9f443825b806";
// from address = "47Ea71715F8049B80eD5C20d105e9C5D7631113f"

// 6 parameters
const char* nonce = "04"; // txn count at the from address
const char* gasPrice = "0c9f71f523"; //54.214653219 gwei
const char* gasLimit = "6349"; // 25417
const char* toAddress = "6B61fd05FA7e73c2de6B1999A390Fee252109072";
const char* valueTrans = "470de4df820000"; // 0.02 ETH
const char* data = "80"; // 0.02 ETH
const int chain_id = 11155111; // sepolia
const char* chain_id_hex = "aa36a7"; // sepolia

void curve_parameters(){
    char *obj_hex_org;
    bignum256 obj_bn_org;
    
    // scep256k1 curve
    obj_hex_org = "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f"; // prime match
    obj_bn_org = (bignum256){0x1ffffc2f, 0x1ffffff7, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0xffffff};
    
    obj_hex_org = "79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"; // Gx match  
    obj_bn_org = (bignum256){0x16f81798, 0x0f940ad8, 0x138a3656, 0x17f9b65b, 0x10b07029, 0x114ae743, 0x0eb15681, 0x0fdf3b97, 0x79be66};
    bn_check_hex(obj_hex_org, obj_bn_org);

    obj_hex_org = "483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8"; // Gy match
    obj_bn_org = (bignum256){0x1b10d4b8, 0x023e847f, 0x01550667, 0x0f68914d, 0x108a8fd1, 0x1dfe0708, 0x11957693, 0x0ee4d478, 0x483ada};
    bn_check_hex(obj_hex_org, obj_bn_org);

    obj_hex_org = "fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141"; // n match
    obj_bn_org = (bignum256){0x10364141, 0x1e92f466, 0x12280eef, 0x1db9cd5e, 0x1fffebaa, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0xffffff};
    bn_check_hex(obj_hex_org, obj_bn_org);    

    obj_hex_org = "9d671cd581c69bc5e697f5e45bcd07c6741496c20e7cf878896cf21467d7d140"; // Hn not match (trezor: 9d671cd581c69bc5e697f5e45bcd07c6741496c20e7cf879dfe92f46681b20a0)
    obj_bn_org = (bignum256){0x081b20a0, 0x1f497a33, 0x09140777, 0x0edce6af, 0x1ffff5d5, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0x7fffff};
    bn_check_hex(obj_hex_org, obj_bn_org);

    // starknet curve
    obj_hex_org = "0800000000000011000000000000000000000000000000000000000000000001"; // prime match
    obj_bn_org = (bignum256){0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00440000, 0x00000000, 0x080000};
    bn_check_hex(obj_hex_org, obj_bn_org);

    obj_hex_org = "06f21413efbe40de150e596d72f7a8c5609ad26c15c915c1f4cdfcb99cee9e89"; // b match
    obj_bn_org = (bignum256){0x1cee9e89, 0x066fe5cc, 0x1245707d, 0x15a4d82b, 0x1a8c5609, 0x0cb6b97b, 0x03785439, 0x027df7c8, 0x06f214};
    bn_check_hex(obj_hex_org, obj_bn_org);
    
    obj_hex_org = "01ef15c18599971b7beced415a40f0c7deacfd9b0d1819e03d723d8bc943cfca"; // Gx match  
    obj_bn_org = (bignum256){0x0943cfca, 0x0b91ec5e, 0x0606780f, 0x19fb361a, 0x0f0c7dea, 0x16a0ad20, 0x1c6defb3, 0x1830b332, 0x01ef15};
    bn_check_hex(obj_hex_org, obj_bn_org);

    obj_hex_org = "005668060aa49730b7be4801df46ec62de53ecd11abe43a32873000c36e8dc1f"; // Gy match
    obj_bn_org = (bignum256){0x16e8dc1f, 0x03980061, 0x0f90e8ca, 0x07d9a235, 0x0ec62de5, 0x0400efa3, 0x1cc2def9, 0x00c15492, 0x005668};
    bn_check_hex(obj_hex_org, obj_bn_org);

    obj_hex_org = "0800000000000010ffffffffffffffffb781126dcae7b2321e66a241adc64d2f"; // n match
    obj_bn_org = (bignum256){0x0dc64d2f, 0x1335120d, 0x19ec8c87, 0x0224db95, 0x1ffffb78, 0x1fffffff, 0x0043ffff, 0x00000000, 0x080000};    
    bn_check_hex(obj_hex_org, obj_bn_org);

    obj_hex_org = "07d9e57c2333766ebaf0ab4cf78bbabb509cf64d14ce60b96021b3f1ea1c688d"; // Hn match
    obj_bn_org = (bignum256){0x0a1c688d, 0x010d9f8f, 0x13982e58, 0x19ec9a29, 0x1babb509, 0x15a67bc5, 0x19baebc2, 0x0f84666e, 0x07d9e5};
    bn_check_hex(obj_hex_org, obj_bn_org);
}

uint8_t* rlp(int data_size, const char* data_hex, uint8_t* packet){
    uint8_t* data = hexToUint8(data_hex);

    memzero(packet, data_size+1);

    packet[0] = 0x80 + data_size;
    memcpy(packet+1, data, data_size);

    // print_arr("pkt", packet, data_size+1);

    return packet;
}

uint8_t* rlph(int data_size, uint8_t* data, uint8_t* packet){
    memzero(packet, data_size+1);

    packet[0] = 0x80 + data_size;
    memcpy(packet+1, data, data_size);

    // print_arr("pkt", packet, data_size+1);

    return packet;
}

int generate_unsigned_txn(uint8_t* public_key, size_t pubkey_len, uint8_t* unsigned_txn){
    // {'accessList': [], 
    //     'blockHash': HexBytes('0x37232cccbd2216fa461a5e87a117b9be11fb1077b6c35ab36e7ba6b3029dd3b7'), 
    //     'blockNumber': 5120444, 
    //     'chainId': 11155111,
    //     'from': '0x1fc35B79FB11Ea7D4532dA128DfA9Db573C51b09', 
    //     'gas': 22000, 
    //     'gasPrice': 55304412496,
    //     'hash': HexBytes('0xe3f047354e5a1fafef1d6dce088eb97a49118cdd68a0a60ea7cfaa63b44a6c37'), 
    //     'input': HexBytes('0x'), 
    //     'maxFeePerGas': 86000000000, 
    //     'maxPriorityFeePerGas': 9000000000, 
    //     'nonce': 9644606, 
    //     'r': HexBytes('0xc515bbb14bbfcdcd3cd359c5674d71bff84ac7352057f07d3a71fbbb86f10e72'), 
    //     's': HexBytes('0x63f5a826aadd3734fce97f67ec89720158f183ff94c4107a88c4162d05eeccbc'), 
    //     'to': '0x47Ea71715F8049B80eD5C20d105e9C5D7631113f', 
    //     'transactionIndex': 237, 
    //     'type': 2, 
    //     'v': 1, 
    //     'value': 500000000000000000, 
    //     'yParity': 1}

    // size_t unsigned_txn_len = 1+ (((strlen(nonce)+strlen(gasPrice)+strlen(gasLimit)+strlen(toAddress)+strlen(valueTrans)+(strlen(data))/2)+6) + 1 + 2;

    unsigned_txn[200];
    memzero(unsigned_txn, 200);

    int i=0, r=0; uint8_t packet[30];
    i += 1; // 1st field

    r = strlen(nonce)/2;
    if (r==1){
        uint8_t* nonceBytes = hexToUint8(nonce);
        unsigned_txn[i] = nonceBytes[0];
        i += 1;
    } else {
        memcpy(unsigned_txn+i, rlp(r, nonce, packet), r+1); // nonce multi
        i += r+1; 
    } 
    
    r = strlen(gasPrice)/2;
    memcpy(unsigned_txn+i, rlp(r, gasPrice, packet), r+1); // gas price
    i += r+1; 
    
    r = strlen(gasLimit)/2;
    memcpy(unsigned_txn+i, rlp(r, gasLimit, packet), r+1); // gas limit
    i += r+1; 
    
    r = strlen(toAddress)/2;
    memcpy(unsigned_txn+i, rlp(r, toAddress, packet), r+1); // to address
    i += r+1; 
    
    r = strlen(valueTrans)/2;
    memcpy(unsigned_txn+i, rlp(r, valueTrans, packet), r+1); // value
    i += r+1;

    r = strlen(data)/2;
    if (r<1){
        unsigned_txn[i] = 0x80; // data 1
        i += 1;
    } else {
        memcpy(unsigned_txn+i, rlp(r, data, packet), r+1); // data multi
        i += r+1; 
    }
    
    r = strlen(chain_id_hex)/2;
    memcpy(unsigned_txn+i, rlp(r, chain_id_hex, packet), r+1); // v = chain id
    i += r+1; 

    unsigned_txn[i] = 0x80; // r
    i += 1;

    unsigned_txn[i] = 0x80; // s

    const int unsigned_txn_len = i+1;

    unsigned_txn[0] = 0xc0 + (unsigned_txn_len-1); // 1st field = packet length excluding first byte
    
    return unsigned_txn_len;
}

void hash256(uint8_t* data, uint8_t* output, size_t size) {
    hasher_Raw(HASHER_SHA3K, data, size, output);
    compare_keys("Unsign_txn hash", output, hash, SHA3_256_DIGEST_LENGTH);
}

void get_keys(const char *mnemonic, const char *passphrase, uint8_t* public_key, uint8_t* private_key,
                size_t publickey_len, size_t privkey_len, uint32_t purpose, uint32_t coin_type, 
                uint32_t account, uint32_t change, uint32_t address_idx) {
    uint8_t seed[64];
    mnemonic_to_seed(mnemonic, passphrase, seed, 0);
    compare_keys("Seed", seed, vseed, 64);

    HDNode node;
    hdnode_from_seed(seed, 64, "secp256k1", &node);
    hdnode_fill_public_key(&node);
    compare_keys("Master_pubkey", node.public_key, m_pubkey, publickey_len);
    compare_keys("Master_chaincode", node.chain_code, m_chaincode, privkey_len); 
    // node_details(node);    

    hdnode_private_ckd(&node, purpose);
    hdnode_fill_public_key(&node); 
    compare_keys("M44_pubkey", node.public_key, m44_pubkey, publickey_len);
    // node_details(node); 

    hdnode_private_ckd(&node, coin_type);
    hdnode_fill_public_key(&node);
    compare_keys("M4460_pubkey", node.public_key, m4460_pubkey, publickey_len);
    // node_details(node); 

    hdnode_private_ckd(&node, account);
    hdnode_fill_public_key(&node);
    compare_keys("M44600_pubkey", node.public_key, m44600_pubkey, publickey_len);
    // node_details(node); 

    hdnode_private_ckd(&node, change);
    hdnode_fill_public_key(&node);
    compare_keys("M446000_pubkey", node.public_key, m446000_pubkey, publickey_len);
    // node_details(node); 

    hdnode_private_ckd(&node, address_idx);
    hdnode_fill_public_key(&node);
    compare_keys("M4460000_pubkey", node.public_key, m4460000_pubkey, publickey_len);
    // node_details(node); 

    memcpy(public_key, node.public_key, publickey_len);
    memcpy(private_key, node.private_key, privkey_len);    
}
int compare_keys(char* name, uint8_t* key1, const char* key2, size_t size){
    uint8_t key2_arr[size];
    
    print_hexarr(name, key2, size, key2_arr);

    int result = memcmp(key1, key2_arr, size);
    if (result==0){
        printf("%s matched!\n", name);
    } else {
        printf("%s UNMATCHED :(\n", name);
    }
}

void node_details(HDNode node){
    printf("\nnode details: child_num[%02x] : depth[%02x]\n", node.child_num, node.depth);
}

uint32_t generate_vrs(const uint8_t *sig, int rec_id, uint32_t v, uint8_t* r, uint8_t* s, size_t sig_len){
    memzero(r, sig_len/2);
    memzero(s, sig_len/2);

    v = 35 + rec_id + (chain_id*2);
    memcpy(r, sig, 32);
    memcpy(s, sig+32, 32);

    return v;
}

void generate_signed_txn(uint8_t* unsigned_txn, uint32_t v, uint8_t* r, uint8_t* s, size_t unsigned_txn_len, uint8_t* signed_txn){
    uint8_t vrs[100];
    memzero(vrs, 100);

    int i=0, l=0; uint8_t out[32];

    l = 4;
    vrs[i+1] = (uint8_t)((v >> 24) & 0xFF);
    vrs[i+2] = (uint8_t)((v >> 16) & 0xFF);
    vrs[i+3] = (uint8_t)((v >> 8) & 0xFF);
    vrs[i+4] = (uint8_t)(v & 0xFF);
    i += l+1; 
    
    l = 32; 
    memcpy(vrs+i, rlph(l, r, out), l+1); // r
    i += l+1; 
    
    l = 32;
    memcpy(vrs+i, rlph(l, s, out), l+1); // s
    i += l+1;

    vrs[0] = 0x84;

    const int vrs_len = i;
    print_arr("vrs", vrs, vrs_len);


    int unsigned_txn_data_len = -1 + unsigned_txn_len - (1+(strlen(chain_id_hex))/2) -2; // removing the first field and the v, r and s fields

    const int signed_txn_len = 1 + 1 + unsigned_txn_data_len + vrs_len; // <length of length field + length field + unsigned_txn_len + vrs vrs>
    signed_txn[signed_txn_len];
    memzero(signed_txn, signed_txn_len);

    i=0;
    signed_txn[i] = 0xf8; // length of length field
    i += 1;

    signed_txn[i] = unsigned_txn_data_len + vrs_len; // length field
    i += 1;

    memcpy(signed_txn+i, &unsigned_txn[1], unsigned_txn_data_len); // exclude the first length field
    i += unsigned_txn_data_len;

    memcpy(signed_txn+i, vrs, vrs_len);

    print_arr("signed txn", signed_txn, signed_txn_len);
    // printf("%d, %d, %d\n", unsigned_txn_len, vrs_len, signed_txn_len);
}

// f8
// 6f
// 02
// 85 051f4d5c00
// 82 55f0
// 94 6b61fd05fa7e73c2de6b1999a390fee252109072
// 87 071afd498d0000
// 80
// 84 01546d71
// a0 fbfd7ac2fe0db0625f6c70dd15880df025a3fac62d7b39d63d073f877b855612
// a0 0b97054ac806c6cf5e2e23d08ff66c54f763d94ce85802552b429dbf325a40de

// f8
// 6f 
// 02 
// 85 051f4d5c00
// 82 55f0
// 94 6b61fd05fa7e73c2de6b1999a390fee252109072
// 87 071afd498d0000
// 80
// 84 01546d71
// a0 8a24c5d86f4cadd603f89e06fd9855e433299b674a00e87c42e305297517bda2
// a0 04be20075eec67d01010280282493fb6d8a815fff5b32d440dc8aeed4f06e9b2

// f8
// 70
// 03
// 85 0c9f71f523
// 82 6349
// 94 6b61fd05fa7e73c2de6b1999a390fee252109072
// 87 470de4df820000
// 81 80
// 84 01546d71
// a0 5676ea98bc0700961e68c2ec5d1a99cba5e423c23e2691b616f19dc7da8d849e
// a0 174ec346c4d2c02588ee73f47405da4bd39051492fb6036f8522099488e01e8b

// f8
// 72
// 03
// 850c9f71f523
// 826349
// 946b61fd05fa7e73c2de6b1999a390fee252109072
// 87470de4df820000
// 8180
// 838401546d72
// a0e8609f77bfb6611efed7561cbcacf279bd3d5d638686e64134f27630c5d48291a0498eeafc7de764ec0e5a988325cfa018f5277e9138381ba0ec519316a4cfec70

// f8
// 70
// 03
// 85 0c9f71f523
// 82 6349
// 94 6b61fd05fa7e73c2de6b1999a390fee252109072
// 87 470de4df820000
// 81 80
// 84 01546d72
// a0 e8609f77bfb6611efed7561cbcacf279bd3d5d638686e64134f27630c5d48291
// a0 498eeafc7de764ec0e5a988325cfa018f5277e9138381ba0ec519316a4cfec70

// f8
// 70
// 03
// 85 0c9f71f523
// 82 6349
// 94 6b61fd05fa7e73c2de6b1999a390fee252109072
// 87 470de4df820000
// 81 80
// 84 01546d71
// a0 c78a06dc321d7bf2c803576d5832a352a317eeb24e7f008f17940fa86c378dfa
// a0 5582556d70f261d6aaad4abcd88e4a71a246ba05858fce4ea9a12fe18015359c

// f8
// 6e
// 03
// 850c9f71f523
// 826349
// 946b61fd05fa7e73c2de6b1999a390fee252109072
// 87470de4df820000
// 8401546d71
// a0da012c2eda51d2b416145e6918338024b6064c3294bd2b5aa015bdc01dd011da
// a043e97e6347f7f3cf1e1aeb4acbc590a8b9859b3df3748f240effacf5017081da

// 02 // hash function type kecceb256

// f8 // length of length field
// 7a // 122 length
// 83 aa36a7 // 11155111 chain id
// 83 932a3e // 9644606 nonce
// 85 0218711a00 // 9000000000 maxPriorityFeePerGas
// 85 1405ffdc00 // 86000000000 maxFeePerGas
// 82 55f0 // 55f0
// 94 47ea71715f8049b80ed5c20d105e9c5d7631113f // to address
// 88 06f05b59d3b20000 // 500000000000000000 value transferred
// 80 // code 
// c0 // 190
// 01 // 1 v
// a0 c515bbb14bbfcdcd3cd359c5674d71bff84ac7352057f07d3a71fbbb86f10e72 // r
// a0 63f5a826aadd3734fce97f67ec89720158f183ff94c4107a88c4162d05eeccbc // s

// (3+3+5+5+2+20+8+0+0+0+32+32)+12 = 122 (length field)

// AttributeDict({
        // 'accessList': [], 
        // 'blockHash': HexBytes('0x37232cccbd2216fa461a5e87a117b9be11fb1077b6c35ab36e7ba6b3029dd3b7'), 
        // 'blockNumber': 5120444, 
        // 'chainId': 11155111, 
        // 'from': '0x1fc35B79FB11Ea7D4532dA128DfA9Db573C51b09', 
        // 'gas': 22000, 
        // 'gasPrice': 55304412496, 
        // 'hash': HexBytes('0xe3f047354e5a1fafef1d6dce088eb97a49118cdd68a0a60ea7cfaa63b44a6c37'), 
        // 'input': HexBytes('0x'), 
        // 'maxFeePerGas': 86000000000, 
        // 'maxPriorityFeePerGas': 9000000000, 
        // 'nonce': 9644606, 
        // 'r': HexBytes('0xc515bbb14bbfcdcd3cd359c5674d71bff84ac7352057f07d3a71fbbb86f10e72'), 
        // 's': HexBytes('0x63f5a826aadd3734fce97f67ec89720158f183ff94c4107a88c4162d05eeccbc'), 
        // 'to': '0x47Ea71715F8049B80eD5C20d105e9C5D7631113f', 
        // 'transactionIndex': 237, 
        // 'type': 2, 
        // 'v': 1, 
        // 'value': 500000000000000000, 
        // 'yParity': 1
        // })

// signature = "c515bbb14bbfcdcd3cd359c5674d71bff84ac7352057f07d3a71fbbb86f10e7263f5a826aadd3734fce97f67ec89720158f183ff94c4107a88c4162d05eeccbc"