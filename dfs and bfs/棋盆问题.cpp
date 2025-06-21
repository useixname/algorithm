#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int net[4][2] = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
char board[N][N];
int n, maxCount;

// 检查从 (x, y) 出发，沿方向 dir 是否可以跳跃
bool chk(int x, int y, int dir) {
    int nx1 = x + net[dir][0], ny1 = y + net[dir][1];       // 第一个位置
    int nx2 = x + 2 * net[dir][0], ny2 = y + 2 * net[dir][1]; // 第二个位置
    if (nx2 < 1 || ny2 < 1 || nx2 > n || ny2 > n) return false; // 检查边界
    if (board[nx1][ny1] == 'Q' && board[nx2][ny2] == '.') return true;
    return false;
}

// 深度优先搜索，计算以 (x, y) 为起点的最大吃子数
int dfs(int x, int y) {
    int localMax = 0; // 当前搜索路径的最大吃子数
    for (int i = 0; i < 4; i++) {
        if (chk(x, y, i)) {
            // 记录跳跃前的状态
            int nx1 = x + net[i][0], ny1 = y + net[i][1];
            int nx2 = x + 2 * net[i][0], ny2 = y + 2 * net[i][1];
            board[nx1][ny1] = '.'; // 吃掉 Q
            board[nx2][ny2] = 'L'; // 跳到新位置
            board[x][y] = '.';     // 原位置变为空位

            // 递归探索
            localMax = max(localMax, 1 + dfs(nx2, ny2));

            // 回溯棋盘状态
            board[nx1][ny1] = 'Q';
            board[nx2][ny2] = '.';
            board[x][y] = 'L';
        }
    }
    return localMax;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    // 遍历所有 L，计算最大吃子数
    maxCount = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 'L') {
                maxCount = max(maxCount, dfs(i, j));
            }
        }
    }

    cout << maxCount << endl;
    return 0;
}
