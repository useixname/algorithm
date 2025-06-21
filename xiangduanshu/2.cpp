#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N],L[N],R[N],s1[N],s2[N];
int n;

int low_bit(int x){
  return x&-x;
}

int sum(int x,int *s){
  int ret=0;
  while(x){
    ret+=s[x];
    x-=low_bit(x);
  }
  return ret;
}

void add(int x,int c,int *s){
  while(x<=n){
    s[x]+=c;
    x+=low_bit(x);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  int len=unique(b+1,b+n+1)-(b+1);
  for(int i=1;i<=n;i++){
    int pos=lower_bound(b+1,b+len+1,a[i])-b;
    L[i]=sum(pos-1,s1);
    add(pos,1,s1);
  }
  for(int i=n;i>=1;i--){
    int pos=lower_bound(b+1,b+len+1,a[i])-b;
    // R[i]=sum(len,s2)-sum(pos,s2);
    //i到n这一段数组中有多少个数小于等于a[i];不包括位置i
    //那么i到n这一段数组中就总共有n-i-sum(pos,s2)个数大于a[i];
    R[i]=n-i-sum(pos,s2);
    add(pos,1,s2);
  }
  for(int i=1;i<=n;i++){
    cout<<L[i]<<" "<<R[i]<<'\n';
  }
  return 0;
}