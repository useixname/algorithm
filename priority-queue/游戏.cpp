#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],f_min[N],f_max[N],q[N];
int n,k;

void get_max(){
  int h=1,t=0;
  for(int i=1;i<=n;i++){
    while(h<=t&&a[i]>=a[q[t]]){
      t--;
    }
    q[++t]=i;
    if(i-q[h]+1>k){
      h++;
    }
    if(i>=k){
      f_max[i-k+1]=a[q[h]];
    }
  }
}

void get_min(){
  int h=1,t=0;
  for(int i=1;i<=n;i++){
    while(h<=t&&a[i]<=a[q[t]]){
      t--;
    }
    q[++t]=i;
    if(i-q[h]+1>k){
      h++;
    }
    if(i>=k){
      f_min[i-k+1]=a[q[h]];
    }
  }
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  get_max();
  get_min();
  int s1=0,s2=0;
  for(int i=1;i<=n-k+1;i++){
    s1+=f_max[i];
    s2+=f_min[i];
  }
  printf("%.2f",(s1*s2*1.0)/((n-k+1)*(n-k+1)));
  return 0;
}