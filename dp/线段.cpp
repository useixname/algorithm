#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int f[N][2];
int l[N], r[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    f[1][0] = r[1] - 1 + r[1] - l[1];
    f[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0] + abs(l[i - 1] - r[i]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i - 1] - r[i]) + r[i] - l[i] + 1),
        f[i][1] = min(f[i - 1][0] + abs(l[i - 1] - l[i]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i - 1] - l[i]) + r[i] - l[i] + 1);
    }
    cout<<min(f[n][0]+n-l[n],f[n][1]+n-r[n]);
    return 0;
}