#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
string s;
int n,ans;
map<string,int>m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int len=1;len+i<=n;len++){
            string ss=s.substr(i,len);
            m[ss]+=1;
            if(m[ss]>=2){
                ans=max(ans,len);
            }
        }
    }
    cout<<ans+1;
    return 0;
}