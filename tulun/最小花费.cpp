#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
const double INF = 1e18;

struct Edge {
    int v, w;
};

vector<Edge> e[N];
double d[N];
bool vis[N];
int n, m;

void dijkstra(int s) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;

    fill(d, d + N, INF);
    memset(vis, 0, sizeof(vis));

    d[s] = 100.0;
    q.push({d[s], s});

    while (!q.empty()) {
        auto [dist, u] = q.top();
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            double cost = d[u] / (1.0 - w / 100.0);

            if (d[v] > cost) {
                d[v] = cost;
                q.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    int a, b;
    cin >> a >> b;

    dijkstra(b);  // 从终点反向跑
    cout << fixed << setprecision(8) << d[a] << '\n';

    return 0;
}