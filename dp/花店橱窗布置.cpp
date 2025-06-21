#include <bits/stdc++.h>
using namespace std;
#define inf -0x3f3f3f3f
int f, v;
int a[101][101];
int dp[101][101];
// dp[i][j]表示前i个花盆放j棵花的最大观赏度
void dfs(int i, int j)
{
    if (j == 0)
        return;
    for (int k = 0; k <= i - j; k++)
        if (dp[i][j] == dp[j + k - 1][j - 1] + a[j][j + k])
        {
            dfs(j + k - 1, j - 1);
            printf("%d ", j + k);
            break;
        }
}
int main()
{
    scanf("%d%d", &f, &v);
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
            scanf("%d", &a[i][j]);
    }
    for (int i = 1; i <= f; i++)
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= f; j++)
        {
            dp[i][j] = inf;
            for (int k = 0; k <= i - j; k++)
                dp[i][j] = max(dp[i][j], dp[j + k - 1][j - 1] + a[j][j + k]);
        }
    printf("%d\n", dp[v][f]);
    dfs(v, f);
}