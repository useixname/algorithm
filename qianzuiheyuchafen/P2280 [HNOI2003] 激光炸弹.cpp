#include <iostream>
#include <cstdio>
using namespace std;
int sum[5002][5002];
int n, m, x, y, v, ans;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x, &y, &v);
        sum[x + 1][y + 1] += v;
    }
    for (int i = 1; i <= 5001; i++)
        for (int j = 1; j <= 5001; j++)
            sum[i][j] += sum[i][j - 1] - sum[i - 1][j - 1] + sum[i - 1][j];
    for (int i = m; i <= 5001; i++)
        for (int j = m; j <= 5001; j++)
            ans = max(ans, sum[i][j] - sum[i][j - m] - sum[i - m][j] + sum[i - m][j - m]);
    printf("%d", ans);
    return 0;
}