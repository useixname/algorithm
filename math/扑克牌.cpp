#include<bits/stdc++.h>
using namespace std;
const int MOD = 10007;

// 快速幂，用于计算模逆元
int qpow(int base, int exp, int mod) {
    int res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 计算组合数 C(n, k) = n! / (k! * (n-k)!)
int comb(int n, int k) {
    if (k > n) return 0;
    int num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * (n - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    return num * qpow(den, MOD - 2, MOD) % MOD; // 使用模逆元计算
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 1;
    cin >> n >> m;
    int t = n;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        ans = ans * comb(t, a[i]) % MOD;
        t -= a[i];
    }
    cout << ans << '\n';
    return 0;
}
