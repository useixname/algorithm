#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N = 1e3 + 10;
int d[N][N], vis[N];
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<>> q;
vector<PII> a[N];
int n, m, ans;

void prim(int s)
{
    memset(vis, 0, sizeof(vis));
    d[s][s] = 0;
    q.push({0, s});
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto ed : a[u])
        {
            int v = ed.first, w = ed.second;
            if (d[s][v] > d[s][u] + w)
            {
                d[s][v] = d[s][u] + w;
                q.push({d[s][v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(d, inf, sizeof(d));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
    {
        prim(i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += d[1][i] + d[i][1];
    }
    cout << ans;
    return 0;
}