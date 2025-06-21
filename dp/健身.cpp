/*
背包最大容量 对应 每一段连续区间天数和 
一个物品 对应 一个计划
一个物品容量 对应 一个计划所需天数 
一个物品价值 对应 一个计划所获增益
至此就抽象成了完全背包问题, 开始快乐的Coding吧!!! >_<
*/
#include <bits/stdc++.h>
#define int long long // 本题数据较大建议开 大数据类型 
using namespace std;
int n, m, q;
int t1[200010], t2[200010], cnt; // 把输入的t1中的每一段连续的区间找出来保存到t2, cnt就是t2中连续区间的个数 
int k[60], s[60];
int dp[200010];
int res;
// 快速幂加速求解, 也可以用系统的, 我主要是锻炼快速幂算法 
int pow2(int n, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans *= n;
        }
        n *= n;
        x /= 2;
    }
    return ans;
}
signed main(void) {
    scanf("%lld %lld %lld", &n, &m, &q);
    // 保存连续区间的天数 
    for (int i = 1; i <= q; i++) {
        scanf("%lld", &t1[i]);
        t2[++cnt] = t1[i] - t1[i - 1] - 1;
    }
    // 处理边界天数 
    if (n != t1[q]) {
        t2[++cnt] = n - t1[q];
    }
    // 对每一个计划所用天数进行预处理, 这里花费的天数就是背包里的每个物品的容量 
    for (int i = 1; i <= m; i++) {
        scanf("%lld %lld", &k[i], &s[i]);
        k[i] = pow2(2, k[i]);
    }
    // 开始进行动态规划 
    for (int f = 1; f <= cnt; f++) { // 先枚举每一个连续区间进行求解最大值 
        memset(dp, 0, sizeof(dp)); // 每一个新的连续区间都需要重新进行动态规划 
        for (int i = 1; i <= m; i++) { // 每一个计划就是完全背包的物品 
            for (int j = k[i]; j <= t2[f]; j++) { // 每一段连续区间的天数就是完全背包的容量 
                dp[j] = max(dp[j], dp[j - k[i]] + s[i]); // 经典完全背包状态转移方程 
            }
        }
        res += dp[t2[f]]; // 把每一段的连续区间的最大值进行统计就是最终值 
    }
    printf("%lld\n", res); // 输出最终值 
    return 0;
}