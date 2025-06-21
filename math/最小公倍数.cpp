#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10;
int a[N], b[N], c[N], vis[N], prim[N];
int n, cnt;
int la, lb, lc;

// 线性筛打素数
void get_prim(){
    for(int i = 2; i <= n; i++){
        if(!vis[i]) prim[++cnt] = i;
        for(int j = 1; j <= cnt && i * prim[j] <= n; j++){
            vis[i * prim[j]] = 1;
            if(i % prim[j] == 0) break;
        }
    }
}

// 将整数 x 拆成数组 b[1..lb]（低位在下标 1）
void zh(int x){
    lb = 0;
    if(x == 0){
        b[++lb] = 0;
        return;
    }
    while(x){
        b[++lb] = x % 10;
        x /= 10;
    }
}

// 用大整数数组 a[1..la] 乘以整数 x（拆到 b[1..lb]），结果保存在 a[] 中
void mul(int x){
    zh(x);
    lc = la + lb;         // 最多 la+lb 位
    // 先清零 c[]
    for(int i = 1; i <= lc; i++) c[i] = 0;

    // 普通高精度乘法
    for(int i = 1; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            c[i + j - 1] += a[i] * b[j];
        }
    }
    // 处理进位
    for(int i = 1; i <= lc; i++){
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    // 去掉最高可能的 0
    while(lc > 1 && c[lc] == 0) lc--;

    // 把 c[] 拷贝回 a[]
    for(int i = 1; i <= lc; i++){
        a[i] = c[i];
    }
    la = lc;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // 1. 筛出所有 ≤ n 的素数
    get_prim();

    // 2. 计算每个素数 p 的最大幂 ret = p^k ≤ n
    vector<int> maxpow(cnt + 1);
    for(int i = 1; i <= cnt; i++){
        long long ret = 1;
        while(ret * prim[i] <= n) ret *= prim[i];
        maxpow[i] = (int)ret;
    }

    // 3. 用高精度乘把这些 p^k 全部乘起来
    a[1] = 1; la = 1;
    for(int i = 1; i <= cnt; i++){
        mul(maxpow[i]);
    }

    // 4. 输出结果
    for(int i = la; i >= 1; i--){
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
