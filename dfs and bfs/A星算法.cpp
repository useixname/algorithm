#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
const int INF = 1e9;
const int net[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

int r[N][N], f[N][N], g[N][N], h[N][N]; // f = g + h, g是实际代价, h是估计代价
int n, m, a, b, c, d;

// 启发式函数: 曼哈顿距离
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* 算法
void a_star(int startX, int startY, int goalX, int goalY) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    memset(g, INF, sizeof(g));
    memset(f, INF, sizeof(f));
    g[startX][startY] = 0;
    h[startX][startY] = heuristic(startX, startY, goalX, goalY);
    f[startX][startY] = g[startX][startY] + h[startX][startY];

    pq.emplace(f[startX][startY], startX, startY);

    while (!pq.empty()) {
        auto [currentF, x, y] = pq.top();
        pq.pop();

        // 如果到达目标节点
        if (x == goalX && y == goalY) {
            cout << "Minimum cost: " << g[x][y] << endl;
            return;
        }

        // 遍历所有相邻节点
        for (int i = 0; i < 8; i++) {
            int nx = x + net[i][0], ny = y + net[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && r[nx][ny] == 0) { // 确保在范围内且可通行
                int newG = g[x][y] + 1; // 假设移动代价为 1
                if (newG < g[nx][ny]) {
                    g[nx][ny] = newG;
                    h[nx][ny] = heuristic(nx, ny, goalX, goalY);
                    f[nx][ny] = g[nx][ny] + h[nx][ny];
                    pq.emplace(f[nx][ny], nx, ny);
                }
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> r[i][j]; // 0 表示可通行，1 表示障碍物
        }
    }
    cin >> a >> b >> c >> d; // 起点 (a, b)，终点 (c, d)

    a_star(a, b, c, d);

    return 0;
}
