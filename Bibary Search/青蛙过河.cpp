#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, x, h[N], s[N], l, r, ans;
bool check(long long y)
{
  for (int i = y; i < n; i++)
    if (s[i] - s[i - y] < 2 * x)
      return 0;
  return 1;
}
int main()
{
  cin >> n >> x;
  for (int i = 1; i < n; i++)
  {
    cin >> h[i];
    s[i] = s[i - 1] + h[i];
  }
  l = 1, r = n+1;
  while (l+1 < r)
  {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
  return 0;
}