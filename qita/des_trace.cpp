#include <iostream>
#include <vector>
#include <array>
#include <bitset>

using namespace std;

// 初始置换表 IP
static const int IP[64] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};

// 逆初始置换表 IP^-1
static const int IP_INV[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};

// 扩展置换表 E
static const int E[48] = {
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};

// P 置换表
static const int P[32] = {
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25
};

// S 盒
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

// PC-1 表
static const int PC1[56] = {
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
};

// PC-2 表
static const int PC2[48] = {
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
};

// 左移轮数
static const int SHIFTS[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

// 工具: 将 bit 向量按表置换
vector<bool> permute(const vector<bool>& in, const int* table, int n) {
    vector<bool> out(n);
    for(int i=0;i<n;i++) out[i] = in[table[i]-1];
    return out;
}

// 左循环移位
vector<bool> leftShift(const vector<bool>& in, int len, int shift) {
    vector<bool> out(len);
    for(int i=0;i<len;i++) out[i] = in[(i+shift)%len];
    return out;
}

// 生成 16 个子密钥
vector<vector<bool>> generateKeys(const vector<bool>& key) {
    vector<bool> permKey = permute(key, PC1, 56);
    vector<bool> C(28), D(28);
    for(int i=0;i<28;i++) { C[i]=permKey[i]; D[i]=permKey[i+28]; }
    vector<vector<bool>> subKeys;
    for(int i=0;i<16;i++) {
        C = leftShift(C,28,SHIFTS[i]);
        D = leftShift(D,28,SHIFTS[i]);
        vector<bool> CD(56);
        for(int j=0;j<28;j++) CD[j]=C[j], CD[j+28]=D[j];
        subKeys.push_back(permute(CD,PC2,48));
    }
    return subKeys;
}

// f 函数
vector<bool> feistel(const vector<bool>& R, const vector<bool>& K) {
    // E 扩展
    vector<bool> ER = permute(R,E,48);
    // 异或
    for(int i=0;i<48;i++) ER[i] = ER[i]^K[i];
    // S 盒替代
    vector<bool> out(32);
    for(int i=0;i<8;i++) {
        int row = ER[i*6]*2 + ER[i*6+5];
        int col = ER[i*6+1]*8 + ER[i*6+2]*4 + ER[i*6+3]*2 + ER[i*6+4];
        int val = S_BOX[i][row][col];
        for(int j=0;j<4;j++) out[i*4+3-j] = (val>>j)&1;
    }
    // P 置换
    return permute(out, P, 32);
}

// DES 主函数
vector<bool> desEncrypt(const vector<bool>& plaintext, const vector<vector<bool>>& subKeys) {
    vector<bool> ip = permute(plaintext, IP, 64);
    vector<bool> L(32), R(32);
    for(int i=0;i<32;i++) L[i]=ip[i], R[i]=ip[i+32];
    for(int i=0;i<16;i++) {
        vector<bool> newL = R;
        vector<bool> f = feistel(R, subKeys[i]);
        vector<bool> newR(32);
        for(int j=0;j<32;j++) newR[j] = L[j] ^ f[j];
        L = newL; R = newR;
    }
    vector<bool> RL(64);
    for(int i=0;i<32;i++) RL[i]=R[i], RL[i+32]=L[i];
    return permute(RL, IP_INV, 64);
}

// 将 hex 字符串转 bit 向量
vector<bool> hex2bits(const string& hex) {
    vector<bool> bits;
    for(char c:hex) {
        int v = isdigit(c)?c-'0':tolower(c)-'a'+10;
        for(int i=3;i>=0;i--) bits.push_back((v>>i)&1);
    }
    return bits;
}

// 将 bit 向量转 hex 字符串
string bits2hex(const vector<bool>& bits) {
    string hex;
    for(int i=0;i<bits.size();i+=4) {
        int v=0;
        for(int j=0;j<4;j++) v = (v<<1) | bits[i+j];
        hex += "0123456789abcdef"[v];
    }
    return hex;
}

int main() {
    string plainHex, keyHex;
    cout << "输入明文（16 hex）: "; cin >> plainHex;
    cout << "输入密钥（16 hex）: "; cin >> keyHex;
    auto plainBits = hex2bits(plainHex);
    auto keyBits = hex2bits(keyHex);
    auto subKeys = generateKeys(keyBits);
    
    // 初始置换
    auto ipBits = permute(plainBits, IP, 64);
    vector<bool> L(32), R(32);
    for(int i=0;i<32;i++) L[i]=ipBits[i], R[i]=ipBits[i+32];

    // 打印表头
    cout << "轮数\tKi\tLi\tRi" << endl;
    cout << "IP\t-\t" << bits2hex(vector<bool>(L.begin(), L.end()))
         << "\t" << bits2hex(vector<bool>(R.begin(), R.end())) << endl;

    // 16 轮迭代并打印
    for(int i=0;i<16;i++) {
        auto prevL = L, prevR = R;
        L = prevR;
        auto f = feistel(prevR, subKeys[i]);
        R.resize(32);
        for(int j=0;j<32;j++) R[j] = prevL[j] ^ f[j];
        cout << (i+1) << "\t" << bits2hex(subKeys[i])
             << "\t" << bits2hex(L)
             << "\t" << bits2hex(R) << endl;
    }

    // 逆置换前合并
    vector<bool> RL(64);
    for(int i=0;i<32;i++) RL[i]=R[i], RL[i+32]=L[i];
    auto cipher = permute(RL, IP_INV, 64);
    cout << "IP-1\t-\t" << bits2hex(vector<bool>(cipher.begin(), cipher.begin()+32))
         << "\t" << bits2hex(vector<bool>(cipher.begin()+32, cipher.end())) << endl;

    return 0;
}