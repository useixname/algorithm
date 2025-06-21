#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;

vector<pair<int, int>> tree[N]; // 邻接表存储 (相邻节点, 边长)
bool visited[N];
int maxDist = 0;         // 当前 DFS 的最大距离
int farthestNode = 0;    // 对应的最远节点
int maxEdgeCount = 0;    // 对应的边数

// DFS，从节点 u 开始，累计距离 dist，经过的边数为 cnt
void dfs(int u, int dist, int cnt) {
    visited[u] = true;
    if(dist > maxDist) {
        maxDist = dist;
        farthestNode = u;
        maxEdgeCount = cnt;
    }
    for(auto &edge : tree[u]) {
        int v = edge.first, w = edge.second;
        if(!visited[v])
            dfs(v, dist + w, cnt + 1);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    // 树有 n 个节点，n-1 条边
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    
    // 第一次 DFS：从任意节点（比如 1）出发，找最远的节点
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(1, 0, 0);
    
    // 第二次 DFS：从第一次找到的最远节点出发，计算直径和对应边数
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(farthestNode, 0, 0);

    cout << maxDist << "\n";
    cout << maxEdgeCount-1 << "\n";
    return 0;
}
