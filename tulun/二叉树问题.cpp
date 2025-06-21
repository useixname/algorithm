#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int d[N], fa[N], vis[N], ans[N];
vector<int> e[N];  // 存储树的邻接表
vector<PII> query[N]; // 记录要查询的节点对
int n, s, ans1, ans2;

// ? BFS 计算树的深度 & 最大宽度
void bfs(int root) {
    memset(d, 0, sizeof(d)); // 确保 d[] 被正确初始化

    queue<int> q;
    q.push(root);
    d[root] = 1;  // 根节点深度为 1
    while (!q.empty()) {
        int layerSize = q.size();  // 当前层的节点数
        ans2 = max(ans2, layerSize); // 记录最大宽度

        for (int i = 0; i < layerSize; i++) {
            int node = q.front();
            q.pop();
            for (int child : e[node]) {
                if (!d[child]) {
                    d[child] = d[node] + 1;
                    q.push(child);
                }
            }
        }
    }
    ans1 = *max_element(d + 1, d + n + 1); // 最大深度
}

// ? 并查集查找带路径压缩
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

// ? Tarjan 求最近公共祖先 (LCA)
void tarjan(int u) {
    vis[u] = 1; // 标记访问
    for (int v : e[u]) {
        if (!vis[v]) {
            tarjan(v);
            fa[v] = u; // 设定父节点
        }
    }
    for (auto t : query[u]) {
        int v = t.first, i = t.second;
        if (vis[v]) ans[i] = find(v); // 找到最近公共祖先
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) { // n-1 条边
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int x, y;
    cin >> x >> y;

    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    query[x].push_back({y, 1});
    query[y].push_back({x, 1});

    bfs(1);  // 计算树的深度和最大宽度
    tarjan(1); // 计算最近公共祖先 LCA

    int lca = ans[1]; // 最近公共祖先
    int dist = (d[x] - d[lca]) * 2 + (d[y] - d[lca]);

    cout << ans1 << '\n'; // 输出最大深度
    cout << ans2 << '\n'; // 输出最大宽度
    cout << dist << '\n'; // 输出 x, y 之间的距离

    return 0;
}
