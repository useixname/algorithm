#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+10;
 
int n, m;  // n: 物品个数，m: 背包容量
int w[110]; // 每个物品的价值（或重量，加法中的“收益”）
int v[110]; // 每个物品的体积（或代价，背包体积）
 
// 0-1 背包：求最大总价值（每个物品只能取一次）
int knapsack01_max() {
    vector<int> f(m+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    return f[m];
}
 
// 完全背包：求最大总价值（每个物品可以无限次使用）
int knapsackComplete_max() {
    vector<int> f(m+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    return f[m];
}
 
// 0-1 背包的方案数 - "满足"型：即允许不选任何物品时也计入1，初始将所有 f[j] 都设为1
int knapsack01_count_satisfy() {
    vector<int> f(m+1, 1); // 对于任意 j，初始状态认为“不选物品”有 1 种方案
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] += f[j - v[i]];
        }
    }
    return f[m];
}
 
// 0-1 背包的方案数 - "恰好满足"型：要求正好填满容量 m，因此 f[0] = 1, 其它 f[j]=0 初始
int knapsack01_count_exact() {
    vector<int> f(m+1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] += f[j - v[i]];
        }
    }
    return f[m];
}
 
// 完全背包的方案数 - "满足"型：允许不选也算1
int knapsackComplete_count_satisfy() {
    vector<int> f(m+1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] += f[j - v[i]];
        }
    }
    return f[m];
}
 
// 完全背包的方案数 - "恰好满足"型
int knapsackComplete_count_exact() {
    vector<int> f(m+1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] += f[j - v[i]];
        }
    }
    return f[m];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    cout << "0-1 Knapsack maximum value: " << knapsack01_max() << "\n";
    cout << "Complete Knapsack maximum value: " << knapsackComplete_max() << "\n";
    cout << "0-1 Knapsack count (satisfy): " << knapsack01_count_satisfy() << "\n";
    cout << "0-1 Knapsack count (exact): " << knapsack01_count_exact() << "\n";
    cout << "Complete Knapsack count (satisfy): " << knapsackComplete_count_satisfy() << "\n";
    cout << "Complete Knapsack count (exact): " << knapsackComplete_count_exact() << "\n";
    
    return 0;
}
