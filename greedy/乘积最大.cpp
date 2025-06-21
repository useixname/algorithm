#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010,M =1000000009;
typedef long long ll;

ll a[N];
int n, k;
ll res = 1;

int main()
{
  cin >> n >> k;

  for(int i = 0;i < n; i++)
  {
    cin >> a[i];
  }

  sort(a,a+n);

  int l = 0,r = n - 1;
  int sigh = 1;   //符号标记
  if(k % 2)    //当k为奇数是，至少取一个最大的数，k--就是偶数则就偶数的求法取求
  {
    res = a[r];
    r--;
    k--;
    if(res < 0) sigh = -1;
  }
//双指针求法
  while(k)
  {
    ll x = a[l] * a[l+1];
    ll y = a[r] * a[r-1];

    if(x * sigh > y * sigh)
    {
      res = x % M * res % M;
      l += 2;
    }
    else
    {
      res = y % M * res % M;
      r -= 2;
    }
     k -= 2;
  }

  cout << res << endl;
  return 0;
}