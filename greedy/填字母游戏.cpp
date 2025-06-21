#include<bits/stdc++.h>
using namespace std;
string s;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>s;
        int n=s.size();
        int l=0,r=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='L'){
                r=i;
                break;
            }
        }
        for(int i=l+1;i<=r-1;i++){
            if(s[i]=='*') cnt++;
        }
        if(cnt==0) cout<<0;
        else if(cnt%2==0) cout<<-1;
        else cout<<1;
        cout<<'\n';
    }
}