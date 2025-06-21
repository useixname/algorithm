#include<bits/stdc++.h>
using namespace std;
const int N=25;
int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int f[N],l[N],a[N];
        int len,maxn=1,ans=0;
        cin>>len;
        for(int i=1;i<=len;i++){
            cin>>a[i];
        }
        for(int i=1;i<=len;i++){
            f[i]=1;
            l[i]=1;
            for(int j=1;j<i;j++){
                if(a[i]>=a[j]){
                    if(f[j]+1>f[i]){
                        f[i]=f[j]+1;
                        l[i]=l[j];
                    }
                    else if(f[j]+1==f[i]){
                        l[i]+=l[j];
                    }
                }
            }
            if(f[i]>maxn){
                maxn=f[i];
                ans=l[i];
            }
            else if(f[i]==maxn){
                ans+=l[i];
            }
        }
        cout<<maxn<<" "<<ans<<'\n';
    }
    return 0;
}