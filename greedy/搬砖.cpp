#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int N = 1010, M = 20010;
int n, m;
int f[M], ans;

struct node
{
    int w, v; // w:体积  v:价值
} a[N];

bool cmp(node a, node b)
{
    return a.v + a.w < b.v + b.w;
}

void solve()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].v;
        m += a[i].w; // 记录总重量
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i].w; j--)
        {

            // 上面所有砖的重量和不能超过它自身的价值
            if (j - a[i].w <= a[i].v)
                f[j] = max(f[j], f[j - a[i].w] + a[i].v);

            ans = max(ans, f[j]); // 更新最大价值
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}