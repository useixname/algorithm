#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 105;
const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f;

vector<int> e[N];
int n, m, q;
int cnt[N]; int dis[N];
queue<int> Q;
bool inq[N];

void bfs(int num, int pos, int lim) {
    queue<int>().swap(Q);
    for(int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[pos] = 0;
    Q.push(pos);
    cnt[num]++;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        if(dis[x] == lim) continue;
        for(int v : e[x]) {
            if(dis[v] == INF) {
                cnt[num]++;
                dis[v] = dis[x] + 1;
                Q.push(v);
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y), e[y].push_back(x);
    }
    long double ans = 0;
    for(int i = 1; i <= q; i++) {
        int pos, lim;
        cin >> pos >> lim;
        bfs(i, pos, lim);
        ans += 1.0 * (1.0 / q) * cnt[i];
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}