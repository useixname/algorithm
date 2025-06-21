#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int f[N],a[110],b[110];
int t,n,p,q;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n>>p>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=q;j>=b[i];j--){
                f[j]=max(f[j],f[j-b[i]]+a[i]);
            }
        }
        bool flag=true;
        for(int i=1;i<=q;i++){
            if(f[i]>=p){
                cout<<i<<'\n';
                flag=false;
                break;
            }
        }
        if(flag) cout<<-1<<'\n';
    }
    return 0;
}