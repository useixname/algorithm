#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
int T,n,t,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    while(T--){
        int cnt=0;
        cin>>n>>t>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
            a[b[i]]-=2;
        }
        sort(a+1,a+n+1);
        int x=upper_bound(a+1,a+n+1,0)-a;
        if(x-1==0) cout<<n<<'\n';
        else{
            for(int i=x-1;i>=1;i--){
                int y=1-a[i];
                if(t>=y) t-=y,cnt++;
                else break;
            }
            cout<<cnt+n-x+1<<'\n';
        }
    }
    return 0;
}