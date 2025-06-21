#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char s[N];
int l,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            l++;
        }
        else{
            if(l){
                l--;
            }
            else{
                ans++;
                l++;
            }
        }
    }
    ans+=l>>1;
    cout<<ans;
    return 0;
}