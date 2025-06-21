#include<bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        int m=2*p+1;
        if(m>n) cout<<-1<<'\n';
        else{
            for(int i=1;i<=n-m;i++){
                cout<<0;
            }
            for(int i=1;i<=m;i++){
                if(i&1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}