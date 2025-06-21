#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r;

bool chk(int x){
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      if(i>=l&&i<=r) return true;
    }
    if(x==1) break;
  }
  if(x>=l&&x<=r) return true;
  return false;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n>>l>>r;
  if(n<l){
    cout<<0;
    return 0;
  }
  if(n<=r){
    int x=r+1;
    while(chk(x)){
      x++;
    }
    int ans=min(n-l+1,x-n);
    cout<<ans;
    return 0;
  }
  else{
    int x=1;
    while(chk(n+x)&&chk(n-x)){
      x++;
    }
    cout<<x;
    return 0;
  }
  return 0;
}