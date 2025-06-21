#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, f[2017][2017], v[2017];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        f[i][i] = v[i] * n;
    for (int i = 2; i <= n; i++)//枚举区间长度
    {
        for (int l = 1; l <= n; l++)//枚举区间起点
        {
            int r = l + i - 1;//枚举区间终点
            if (r > n)
                break;
            f[l][r] = max(f[l][r - 1] + v[r] * (n - i + 1), f[l + 1][r] + v[l] * (n - i + 1));
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}