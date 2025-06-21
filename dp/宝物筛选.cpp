#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int f[N][N], v[N], w[N], s[N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= s[i] && k * w[i] <= j; k++)
            {
                // k == 0时包含了f[i - 1][j]这种情况
                f[i][j] = max(f[i][j], f[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << f[n][m];
    return 0;
}
