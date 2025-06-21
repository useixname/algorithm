#include <bits/stdc++.h>

using namespace std ;
const int N = 5e3 + 10 ;
int pre[N] , suf[N] ; //定义pre[i]表示以i结尾的最长的上升子序列长度 , suf[i]表示以i开头的最长上升子序列长度
int n , a[N] , ans ;


int main()
{
  cin >> n ;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
  a[0] = -1;
  //预处理出 pre 、 suf 数组 
  for(int i = 1 ; i <= n ; i++) 
  {
    pre[i] = 1 ;
    for(int j = 1 ; j < i ; j++)
      if ( a[j] < a[i] ) pre[i] = max(pre[i] , pre[j] + 1) ;
  }
  for(int i = n ; i >= 1 ; i--)
  {
    suf[i] = 1 ;
    for(int j = n ; j > i ; j--)
      if ( a[j] > a[i] ) suf[i] = max(suf[i] , suf[j] + 1) ;
  }
  for(int i = 0 ; i <= n ; i++)
  {
    for(int j = i + 2 ; j <= n ; j++)
    {
      if ( a[j] == a[i] + 1 ) ans = max(ans , pre[i] + suf[j]) ;
      else if ( a[j] > a[i] + 1 ) ans = max(ans , pre[i] + suf[j] + 1) ;
      if ( a[j] > 0 ) ans = max(ans , suf[j] + 1) ;
    }
    if ( i < n ) ans = max(ans , pre[i] + 1) ;
  }
  cout << ans ;
  return 0 ;
}