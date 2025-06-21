#include <bits/stdc++.h>
using namespace std;

int n;
int u, v;
vector<int> mp[200005];
long long w[200005];
long long ans1, ans2;

void solve(int x)
{
    long long max1 = 0, max2 = 0;
    long long sum1 = 0, sum2 = 0;
    for(auto i : mp[x])
    {
        if(w[i] >= max1) max2 = max1, max1 = w[i];
        else if(w[i] >= max2) max2 = w[i];
        sum1 += w[i];
        sum2 += w[i] * w[i];
    }
    ans1 = max(ans1, max1 * max2);
    ans2 += sum1 * sum1 - sum2;
    ans2 %= 10007;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++)
    {
        scanf("%d %d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++)
        solve(i);
    printf("%lld %lld", ans1, ans2);
    return 0;
}