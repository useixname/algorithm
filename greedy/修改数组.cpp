#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int t,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int x=0,y=0,l=0,r=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!l&&a[i]==1){
                l=i;
            }
            if(a[i]==1){
                r=i;
            }
        }
        if(r==l){
            if(r==0) x=0;
            else x=1;
        }
        else x=r-l+1;
        for(int i=l+1;i<=r-1;i++){
            if(a[i]==0){
                a[i]=1;
                y++;
            }
        }
        cout<<x-y<<'\n';
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}