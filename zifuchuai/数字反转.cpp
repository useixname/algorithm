#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
char a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>a+1;
    int n=strlen(a+1);
    if(n==1){
        cout<<a+1;
        return 0;
    }
    bool flag=0,flag1=0;
    if(a[1]=='-'||a[1]=='+'){
        flag1=1;
        cout<<a[1];
    }
    for(int i=n;i>=1+flag1;i--){
        if(a[i]=='0'&&!flag){
            continue;
        }
        else{
            flag=1;
            cout<<a[i];
        }
    }
    if(!flag) cout<<0;
    return 0;
}