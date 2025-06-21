#include <bits/stdc++.h>
using namespace std;

const int N = 100010;  // 假设最多10万节点
vector<int> tree[N];   // 邻接表存树
int depth[N], fa[N][20];  // fa[i][j] 表示 i 的 2^j 祖先
int max_depth = 0;

// DFS 计算深度 & 预处理父节点信息（倍增法）
void dfs(int u, int parent) {
    fa[u][0] = parent;  // 直接父节点
    for (int j = 1; j < 20; j++) {
        if (fa[u][j - 1] != -1)
            fa[u][j] = fa[fa[u][j - 1]][j - 1];  // 2^j 祖先
        else
            fa[u][j] = -1;
    }

    for (int v : tree[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        max_depth = max(max_depth, depth[v]);
        dfs(v, u);
    }
}

// BFS 计算树的最大宽度
int get_max_width(int root) {
    queue<int> q;
    q.push(root);
    int max_width = 0;

    while (!q.empty()) {
        int size = q.size();
        max_width = max(max_width, size);
        for (int i = 0; i < size; i++) {
            int u = q.front(); q.pop();
            for (int v : tree[u]) {
                if (depth[v] > depth[u]) q.push(v);
            }
        }
    }
    return max_width;
}

// 倍增法求 LCA
int get_LCA(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);  // 保证 x 更深

    // 让 x 和 y 处于同一深度
    for (int j = 19; j >= 0; j--) {
        if (fa[x][j] != -1 && depth[fa[x][j]] >= depth[y])
            x = fa[x][j];
    }
    if (x == y) return x;

    // 同步跳跃找 LCA
    for (int j = 19; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];  // LCA 即 x 的父节点
}

// 计算两点间距离
int get_distance(int x, int y) {
    int lca = get_LCA(x, y);
    return depth[x] + depth[y] - 2 * depth[lca];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;  // 结点个数

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(fa, -1, sizeof fa);
    depth[1] = 0;
    dfs(1, -1);  // 以 1 号节点为根构建

    int x, y;
    cin >> x >> y;  // 需要求距离的两个节点

    cout << max_depth << endl;
    cout << get_max_width(1) << endl;
    cout << get_distance(x, y) << endl;

    return 0;
}
