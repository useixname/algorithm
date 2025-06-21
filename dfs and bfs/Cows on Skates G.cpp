#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 115;
char a[N][N];      // 迷宫地图
int n, m, flag = 0; // 终点标志
vector<PII> ret;   // 记录路径

void dfs(int x, int y) {
    if (flag) return; // 找到路径后，立即停止搜索
    if (x == n && y == m) { // 终点
        flag = 1;
        ret.push_back({n, m});
        for (auto t : ret) cout << t.first << " " << t.second << '\n';
        return;
    }
    if (x > n || y > m || x <= 0 || y <= 0 || a[x][y] == '*') return;

    a[x][y] = '*';  // 标记访问
    ret.push_back({x, y});  // 记录路径

    dfs(x + 1, y); // 向下
    dfs(x, y + 1); // 向右
    dfs(x - 1, y); // 向上
    dfs(x, y - 1); // 向左

    ret.pop_back(); // 回溯
    a[x][y] = '.';  // 恢复状态
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dfs(1, 1);
    return 0;
}
