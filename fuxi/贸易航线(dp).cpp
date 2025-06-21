#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
LL dp[N][11];  // dp[i][j]: 到第i个地点，状态为j的最大收益
int g[N][11];  // g[i][j]: 第i行第j个商品的值

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // 读入商品价格
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> g[i][j];

    // 初始化DP表
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = -1e18;
    dp[0][0] = 0;

    // 状态转移
    for (int i = 1; i <= n; ++i) {
        // 什么都不干，继承上一行状态
        for (int j = 0; j <= m; ++j)
            dp[i][j] = dp[i - 1][j];

        // 跨列“卖出”到空仓
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] != -1)
                dp[i][0] = max(dp[i][0], dp[i][j] + g[i][j]);
        }

        // 从空仓“买入”任意列 j
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i][0] - g[i][j]);
        }
    }

    cout << dp[n][0] * k << "\n";
    return 0;
}

/*
为什么这一版是对的
空仓状态有保留：我们确实在 dp[i][0] 里同时继承了
昨天下午的空仓 dp[i-1][0]，也考虑了“卖出持仓到空仓”的情况。
跨列转换：在“卖出”那一步里，for j 循环把
所有 j 列的 dp[i-1][j] + g[i][j] 都算进去了，保证了可以从任何一列切换到空仓。
买入也跨列：同理，下一步的买入是从当天最佳空仓 dp[i][0]，向任意一列 j 买入。
*/