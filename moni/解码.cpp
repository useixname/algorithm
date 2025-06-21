#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char s[N],ans[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(!(s[i]>='1'&&s[i]<='9')){
            if(s[i+1]>='1'&&s[i+1]<='9'){
                for(int j=1;j<=s[i+1]-'0';j++){
                    cout<<s[i];
                }
                i+=1;
            }
            else{
                cout<<s[i];
            }
        }
    }
    return 0;
}