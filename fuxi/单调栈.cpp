#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],q[N],ans[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int top=0;
    for(int i=1;i<=n;i++){
        while(top>0&&a[i]>=a[q[top]]){
            ans[q[top]]=i;
            top--;
        }
        q[++top]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}