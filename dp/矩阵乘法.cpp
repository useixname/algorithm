#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unordered_map<int,ll> un_map;
const int MOD = 1000000007;
 
// 采用二维 DP，dp[i][j] 为一个哈希表，键为当前路径乘积（若达到 n 则记作 n），值为方案数
// 注意：若路径乘积 ≥ n，我们统一记作 n，以表示“满足得分不小于 n”的状态。
 
int r, s, thresh; // r行, s列, thresh 为题目中给定的 n (得分阈值)
 
// 使用二维 vector 存储 dp，每个元素是 unordered_map<int,ll>
vector<vector<unordered_map<int,ll>>> dp;
 
// 计算 newProd = min(oldProd * cell, thresh)
int updateProd(int oldProd, int cell, int thresh) {
    // 如果旧乘积已经达到阈值，则保持阈值
    if(oldProd >= thresh) return thresh;
    ll prod = (ll) oldProd * cell;
    if(prod >= thresh) return thresh;
    return (int) prod;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> r >> s >> thresh;
    vector<vector<int>> grid(r+1, vector<int>(s+1));
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= s; j++){
            cin >> grid[i][j];
        }
    }
    
    // 初始化 dp 数组 (r+1) x (s+1)
    dp.assign(r+1, vector<unordered_map<int,ll>>(s+1));
    
    // 初始状态：从 (1,1) 出发，初始乘积为 grid[1][1]，若其 >= thresh 则记为 thresh
    int prod0 = grid[1][1] >= thresh ? thresh : grid[1][1];
    dp[1][1][prod0] = 1;
    
    // 递推状态：遍历每个格子
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= s; j++){
            // 如果该状态没有方案，跳过
            if(dp[i][j].empty()) continue;
            // 遍历当前状态的所有乘积
            for(auto &entry : dp[i][j]){
                int curProd = entry.first;
                ll ways = entry.second;
                // 向下移动：到 (i+1, j)
                if(i + 1 <= r){
                    int newProd = updateProd(curProd, grid[i+1][j], thresh);
                    dp[i+1][j][newProd] = (dp[i+1][j][newProd] + ways) % MOD;
                }
                // 向右移动：到 (i, j+1)
                if(j + 1 <= s){
                    int newProd = updateProd(curProd, grid[i][j+1], thresh);
                    dp[i][j+1][newProd] = (dp[i][j+1][newProd] + ways) % MOD;
                }
            }
        }
    }
    
    // 答案为从 (r,s) 出发所有方案中，乘积状态为 thresh 的方案数（即乘积>=thresh）
    ll ans = dp[r][s][thresh] % MOD;
    cout << ans << "\n";
    
    return 0;
}
