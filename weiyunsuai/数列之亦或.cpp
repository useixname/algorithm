#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int main()
{
    scanf("%lld", &n);
    if (n & 1)
    {
        ans = (n - 1 >> 1) + 1;
        ans &= 1;
    }
    else
    {
        ans = (n - 1 - 1 >> 1) + 1;
        ans &= 1;
        ans ^= n;
    }
    printf("%lld\n", ans);
    return 0;
}