// ??????? O(n)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=3000005;
int n,a[N],ans[N],q[N];

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  
  int top=0;  //????????????
  for(int i=1; i<=n; i++){
    while(top>0 && a[q[top]]<a[i]){
      ans[q[top]]=i; //?????????
      top--;         //????????
    }
    q[++top]=i;      //????????
  }
  
  for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}