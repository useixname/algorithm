#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, s = 1, t, a[10005][105];
int main()
{
    cin >> n >> m;
    a[0][0] = 1;
    for (i = 1; i <= 10000; i++)
        for (j = 0; j <= 100; j++)
            a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % 10007;
    for (i = 1; i <= m; i++)
    {
        cin >> t;
        s = s * a[n][t] % 10007;
        n -= t;
    }
    cout << s;
    return 0;
}