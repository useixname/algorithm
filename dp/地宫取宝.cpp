#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF -(1LL << 60)

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<long long>> grid(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 初始化动态规划表，每个位置存储一个map，键为(c, max_val)，值为方案数
    vector<vector<map<pair<long long, long long>, long long>>> dp(n, vector<map<pair<long long, long long>, long long>>(m));

    // 处理起点 (0, 0)
    long long first_val = grid[0][0];
    dp[0][0][{1, first_val}] = 1; // 拿的情况
    dp[0][0][{0, INF}] = 1; // 不拿的情况

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue; // 已处理过起点

            // 当前格子的map
            map<pair<long long, long long>, long long> current;

            // 可能的前驱方向：左边和上边
            vector<pair<int, int>> sources;
            if (j > 0) sources.push_back({i, j - 1});
            if (i > 0) sources.push_back({i - 1, j});

            // 遍历每个前驱
            for (auto& source : sources) {
                int si = source.first;
                int sj = source.second;

                for (auto& entry : dp[si][sj]) {
                    long long c_prev = entry.first.first;
                    long long max_prev = entry.first.second;
                    long long cnt = entry.second;

                    long long current_val = grid[i][j];

                    if (current_val > max_prev) {
                        // 可以选择拿或不拿
                        // 不拿的情况
                        current[{c_prev, max_prev}] = (current[{c_prev, max_prev}] + cnt) % MOD;

                        // 拿的情况，c_prev + 1 不能超过k
                        long long new_c = c_prev + 1;
                        if (new_c <= k) {
                            long long new_max = current_val;
                            current[{new_c, new_max}] = (current[{new_c, new_max}] + cnt) % MOD;
                        }
                    } else {
                        // 只能不拿
                        current[{c_prev, max_prev}] = (current[{c_prev, max_prev}] + cnt) % MOD;
                    }
                }
            }

            dp[i][j] = current; // 更新dp[i][j]的状态
        }
    }

    // 统计在终点位置，c=k的所有情况的总和
    long long result = 0;
    for (auto& entry : dp[n - 1][m - 1]) {
        if (entry.first.first == k) {
            result = (result + entry.second) % MOD;
        }
    }

    cout << result << endl;

    return 0;
}
