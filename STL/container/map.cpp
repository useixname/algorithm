#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// 倒着分配。这样既能保证方案有效（保质期在），又能保证最优（最小）。
struct node
{
	int a, b, c;
	friend bool operator<(node x, node y)
	{
		return x.a > y.a;
	}
} a[N];
bool comp(node x, node y) { return x.b > y.b; } // 按保质期从大到小排序
int t, n;
priority_queue<node> q; // 按单价
int main()
{
	// 请在此输入您的代码
	cin >> t >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	sort(a + 1, a + n + 1, comp);
	int j = 1;
	long long ans = 0;
	for (int i = t; i >= 1; i--)
	{
		while (j <= n && a[j].b >= i)
			q.push(a[j++]);
		if (q.empty())
		{
			cout << -1;
			return 0;
		}
		node tmp = q.top();
		q.pop();
		ans += tmp.a;
		tmp.c--;
		if (tmp.c)
			q.push(tmp);
	}
	cout << ans;
	return 0;
}