#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MOD = 100000007;  // 10^8 + 7
// dp[i][r]：前 i 个差值使得加权和模 n 为 r 的方案数
// 维度： i 从 0 到 n-1，余数 r 从 0 到 n-1
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    
    // 特殊情况：n==1，没有差值，序列只有一个数 x1。x1 必须等于 s，只有一种方案。
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    
    // dp 数组维度： (n) x (n)
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;  // 0 个差值，和为 0
  
    // 对于 i 从 0 到 n-2（即一共 n-1 个差值）
    // i 表示已经处理了 i 个差值，接下来处理第 i+1 个
    for (int i = 0; i < n - 1; i++){
        for (int r = 0; r < n; r++){
            if(dp[i][r] == 0) continue;
            // 计算权值： 对于第 i+1 个差值，其权值为 n - (i+1)
            int weight = n - (i + 1);
            // 选择 d = a
            int r1 = (r + (ll)weight * a) % n;
            if(r1 < 0) r1 += n;
            dp[i+1][r1] = (dp[i+1][r1] + dp[i][r]) % MOD;
            // 选择 d = -b
            int r2 = (r + (ll)weight * (-b)) % n;
            if(r2 < 0) r2 += n;
            dp[i+1][r2] = (dp[i+1][r2] + dp[i][r]) % MOD;
        }
    }
    
    // 设 R = s mod n （保证 R 非负）
    int R = ((s % n) + n) % n;
    cout << dp[n-1][R] % MOD << "\n";
    return 0;
}
