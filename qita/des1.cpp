#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROUNDS 16

// —— 常量表 ——
// 初始置换 IP
static const int IP[64] = {
    58,50,42,34,26,18,10,2, 60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6, 64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,  59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,  63,55,47,39,31,23,15,7
};
// 逆初始置换 IP??
static const int IP_INV[64] = {
    40,8,48,16,56,24,64,32, 39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30, 37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28, 35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26, 33,1,41,9,49,17,57,25
};
// PC-1
static const int PC1[56] = {
    57,49,41,33,25,17,9, 1,58,50,42,34,26,18,
    10,2,59,51,43,35,27, 19,11,3,60,52,44,36,
    63,55,47,39,31,23,15, 7,62,54,46,38,30,22,
    14,6,61,53,45,37,29, 21,13,5,28,20,12,4
};
// PC-2
static const int PC2[48] = {
    14,17,11,24,1,5,   3,28,15,6,21,10,
    23,19,12,4,26,8,  16,7,27,20,13,2,
    41,52,31,37,47,55, 30,40,51,45,33,48,
    44,49,39,56,34,53, 46,42,50,36,29,32
};
// E 扩展
static const int E[48] = {
    32,1,2,3,4,5, 4,5,6,7,8,9,
    8,9,10,11,12,13,12,13,14,15,16,17,
    16,17,18,19,20,21,20,21,22,23,24,25,
    24,25,26,27,28,29,28,29,30,31,32,1
};
// P 置换
static const int P[32] = {
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25
};
// S-盒
static const int S_BOX[8][4][16] = {
    {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
     {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
     {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
     {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
    {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
     {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
     {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
     {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
    {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
     {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
     {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
     {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
    {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
     {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
     {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
     {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
    {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
     {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
     {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
     {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
    {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
     {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
     {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
     {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
    {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
     {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
     {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
     {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
    {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
     {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
     {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
     {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
};
static const int SHIFTS[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

// 通用置换
void permute(const int *perm, int plen, const int *in, int ilen, int *out) {
    for(int i = 0; i < plen; i++)
        out[i] = in[ perm[i] - 1 ];
}
// 左循环移位
void left_rotate(int *bits, int len, int shift) {
    int tmp[28];
    memcpy(tmp, bits, shift * sizeof(int));
    memmove(bits, bits + shift, (len - shift) * sizeof(int));
    memcpy(bits + len - shift, tmp, shift * sizeof(int));
}

// 将 “Fang Rao” ASCII 转成带奇偶校验位的 64 bit
// 输出到 keysand[64]
void ascii_key_with_parity(int keysand[64]) {
    const char *k = "Fang Rao";  // 8 字符
    int cnt = 0;
    for(int i = 0; k[i]; i++) {
        int parity = 1;
        for(int b = 6; b >= 0; b--) {
            int bit = (k[i] >> b) & 1;
            keysand[cnt++] = bit;
            parity ^= bit;
        }
        keysand[cnt++] = parity;
    }
}

// 生成子密钥（使用 keysand[64]）
void generate_subkeys(int keysand[64], int subkeys[16][48]) {
    int key56[56], C[28], D[28];
    permute(PC1, 56, keysand, 64, key56);
    memcpy(C, key56, 28*sizeof(int));
    memcpy(D, key56+28, 28*sizeof(int));
    for(int r=0; r<MAX_ROUNDS; r++){
        left_rotate(C,28,SHIFTS[r]);
        left_rotate(D,28,SHIFTS[r]);
        int CD[56];
        memcpy(CD, C, 28*sizeof(int));
        memcpy(CD+28, D,28*sizeof(int));
        permute(PC2,48,CD,56,subkeys[r]);
    }
}

// Feistel 轮函数
void feistel(const int *R, const int *subkey, int *out32) {
    int ER[48], B[32];
    permute(E,48,R,32,ER);
    for(int i=0;i<48;i++) ER[i]^=subkey[i];
    for(int i=0;i<8;i++){
        int row = (ER[i*6]<<1) | ER[i*6+5];
        int col = (ER[i*6+1]<<3)|(ER[i*6+2]<<2)|(ER[i*6+3]<<1)|ER[i*6+4];
        int v = S_BOX[i][row][col];
        for(int b=0;b<4;b++)
            B[i*4+(3-b)] = (v>>b)&1;
    }
    permute(P,32,B,32,out32);
}

// DES 加密，用 subkeys 进行 16 轮
void des_encrypt_block(const int *in64, int *out64, int subkeys[16][48]) {
    int ip[64], L[32], R[32];
    permute(IP,64,in64,64,ip);
    memcpy(L,ip,32*sizeof(int));
    memcpy(R,ip+32,32*sizeof(int));
    for(int r=0;r<MAX_ROUNDS;r++){
        int newL[32], newR[32], f[32];
        memcpy(newL,R,32*sizeof(int));
        feistel(R, subkeys[r], f);
        for(int i=0;i<32;i++) newR[i]=L[i]^f[i];
        memcpy(L,newL,32*sizeof(int));
        memcpy(R,newR,32*sizeof(int));
    }
    int pre[64];
    memcpy(pre,R,32*sizeof(int));
    memcpy(pre+32,L,32*sizeof(int));
    permute(IP_INV,64,pre,64,out64);
}

// hexstr -> bits64
void hexstr_to_bits(const char *hex, int *bits64) {
    for(int i=0;i<16;i++){
        char c=hex[i];
        int v=isdigit(c)?c-'0':tolower(c)-'a'+10;
        for(int b=3;b>=0;b--)
            bits64[i*4+(3-b)]=(v>>b)&1;
    }
}

// bits64 -> hexstr
void bits64_to_hex16(const int *bits64, char *hex16) {
    static const char *H="0123456789abcdef";
    for(int i=0;i<16;i++){
        int v=(bits64[i*4]<<3)|(bits64[i*4+1]<<2)
             |(bits64[i*4+2]<<1)|bits64[i*4+3];
        hex16[i]=H[v];
    }
    hex16[16]='\0';
}

int main(){
    int keysand[64], subkeys[16][48];
    int plaintext[64], ciphertext[64];
    char plainHex[17], cipherHex[17], keyHexDummy[1];

    // 1. 用 ASCII+"Fang Rao" 生成 keysand
    ascii_key_with_parity(keysand);

    // 2. 生成子密钥
    generate_subkeys(keysand, subkeys);

    // 3. 读取明文 hex
    printf("输入明文（16 hex）: ");
    scanf("%16s", plainHex);

    // 4. 将明文转 bits
    hexstr_to_bits(plainHex, plaintext);

    // 5. 加密
    des_encrypt_block(plaintext, ciphertext, subkeys);

    // 6. 输出密文
    bits64_to_hex16(ciphertext, cipherHex);
    printf("输出密文: %s\n", cipherHex);

    return 0;
}
