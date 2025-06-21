#include <cstdio>
#define LL long long
LL dp[25][25][25];

LL w(LL a, LL b, LL c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    else if (a < b && b < c)
    {
        if (!dp[a][b][c - 1])
        {
            dp[a][b][c - 1] = w(a, b, c - 1);
        }
        if (!dp[a][b - 1][c - 1])
        {
            dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        }
        if (!dp[a][b - 1][c])
        {
            dp[a][b - 1][c] = w(a, b - 1, c);
        }
        dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
    }

    else
    {
        if (!dp[a - 1][b][c])
        {
            dp[a - 1][b][c] = w(a - 1, b, c);
        }
        if (!dp[a - 1][b - 1][c])
        {
            dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        }
        if (!dp[a - 1][b][c - 1])
        {
            dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        }
        if (!dp[a - 1][b - 1][c - 1])
        {
            dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        }
        dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b][c - 1] + dp[a - 1][b - 1][c] - dp[a - 1][b - 1][c - 1];
    }
    return dp[a][b][c];
}

int main()
{
    LL a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c))
    {
        if (a == -1 && b == -1 && c == -1)
            return 0;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}