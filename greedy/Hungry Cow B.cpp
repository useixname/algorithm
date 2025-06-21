#include <bits/stdc++.h>
using namespace std;
long long n, t, sum, ans, pos, d[100010], b[100010];
int main()
{
    scanf("%lld%lld", &n, &t);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &d[i], &b[i]);
        pos = min(sum, d[i] - d[i - 1]);
        sum -= pos, ans += pos, sum += b[i];
    }
    printf("%lld", ans + min(sum, t - d[n] + 1));
    return 0;
}