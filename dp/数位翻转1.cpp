#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll NEG_INF = LLONG_MIN / 4;
const int MAXN = 1000000 + 50;

int n, m;
ll orig[MAXN];   // 原数组 a[i]
ll delta[MAXN];  // 增益 Δ[i] = f(a[i]) - a[i]
// 下面两个数组用于 Solve()
ll dp[MAXN];
ll Maxv[MAXN];

// 翻转 x 的二进制（去掉前导 0）
// 例如 x=11 (1011_2) -> 1101_2 = 13
ll flip_binary(ll x) {
    if (x == 0) return 0;
    vector<int> bits;
    while (x) {
        bits.push_back(x & 1);
        x >>= 1;
    }
    ll res = 0;
    // bits[0] 是最低位，bits.back() 是最高位
    for (int b : bits) {
        res = (res << 1) | b;
    }
    return res;
}

// 在 delta[1..n] 上，选至多 m 段，求最大子数组和（返回的是增益 G）
ll Solve() {
    // Maxv[j] 表示上一趟 i-1 完成后，dp 最优前缀
    // dp[j] 表示本趟 i 完成后，以第 j 个位置结束的“恰好 i 段”的最优值
    // 这里我们把原来代码里的 a[j] 换成 delta[j]
    
    // 初始化
    // 对于 i=0 段，只有 dp[0]=0，其它都不可能
    Maxv[0] = 0;
    for (int j = 1; j <= n; j++) {
        Maxv[j] = NEG_INF;
    }

    // 对于每一个段数 i=1..m
    for (int i = 1; i <= m; ++i) {
        // dp[j] 要从 j=i..n-(m-i) 范围内有效，越界处设为 -inf
        // 首先把 j=i-1 处设为 -inf（j<i 时不可能恰好分 i 段）
        dp[i-1] = NEG_INF;
        // 然后从 j=i 开始扫到 j = n-(m-i)
        // 这样保证后面还剩下至少 (m-i) 个位置给剩余的段
        for (int j = i; j <= n - (m - i); ++j) {
            // dp[j] = max(  // 在位置 j 结束时，恰好 i 段
            //    dp[j-1] + delta[j],      // 接续当前第 i 段
            //    Maxv[j-1] + delta[j]     // 在 j 位置新开第 i 段
            // )
            ll extend = (dp[j-1] == NEG_INF ? NEG_INF : dp[j-1] + delta[j]);
            ll open_new = (Maxv[j-1] == NEG_INF ? NEG_INF : Maxv[j-1] + delta[j]);
            dp[j] = max(extend, open_new);
        }
        // 更新 Maxv 为 dp 的前缀最值
        Maxv[i-1] = NEG_INF;
        for (int j = i; j <= n - (m - i); ++j) {
            // Maxv[j] = max( Maxv[j-1], dp[j] )
            Maxv[j] = (j == i
                ? dp[j]
                : max(Maxv[j-1], dp[j]));
        }
    }

    // 最后答案是 dp[j] 在 j=m..n 的最大值
    ll best = NEG_INF;
    for (int j = m; j <= n; ++j) {
        best = max(best, dp[j]);
    }
    // 如果所有增益都≤0，也可以选择 0 段，增益为 0
    return max(best, 0LL);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    ll S = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> orig[i];
        S += orig[i];
        // 计算增益
        delta[i] = flip_binary(orig[i]) - orig[i];
    }

    ll G = Solve();
    cout << (S + G) << "\n";
    return 0;
}
