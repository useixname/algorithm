#include <iostream>
#include <cstdio>
using namespace std;
int f[10010];
int sum[10010];
int w[10010];
int m, n;
const int inf = 99999999;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = inf;
        cin >> w[i];
        sum[i] = sum[i - 1] + w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] += 2 * m;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            f[j] = min(f[j], f[j - i] + sum[i]);
        }
    }
    cout << f[n] - m;
    return 0;
}