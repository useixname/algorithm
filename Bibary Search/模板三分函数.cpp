#include <bits/stdc++.h>
#define ri register int
using namespace std;
#define inf 0x3f3f3f3f
const int N = 1e4 + 10;
int T;
int n;
int a[N], b[N], c[N];
double clac(double x)
{
    double ans = -inf;
    for (ri i = 1; i <= n; i++)
        ans = max(ans, a[i] * 1.0 * x * x + b[i] * 1.0 * x + c[i]);
    return ans;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (ri i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        double l = 0, r = 1000;
        while (r - l > 1e-9)
        {
            double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
            if (clac(mid1) > clac(mid2))
                l = mid1;
            else
                r = mid2;
        }
        printf("%.4lf\n", clac(l));
    }
}