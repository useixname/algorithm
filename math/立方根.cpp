#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define MAX_X 10000
using namespace std;
int a[MAX_X + 5];

void init()
{
	for (int i = 1; i <= 10000; i++)
	{
		a[i] = (i * i * i);
	}
}

int i = 1, ans = 0;
void solve()
{
	int x;
	cin >> x;
	for (; i <= 10000; i++)
	{
		if (a[i] > x)
		{
			break;
		}
		ans += (a[i] - a[i - 1]) * (i - 1);
	}
	cout << ans + (i - 1) * (x - a[i - 1] + 1) << "\n";
}
signed main()
{
	init();
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}