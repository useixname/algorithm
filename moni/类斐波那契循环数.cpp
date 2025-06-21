#include<bits/stdc++.h>
using namespace std;
#define maxn 1e7
int a[10],s[1010];

bool chk(int x){
    memset(s,0,sizeof(s));
    int n=1;
    while(x){
        a[n++]=x%10;
        x/=10;
    }
    n--;
    for(int i=1;i<=n;i++){
        s[i]=a[n-i+1];
    }
    for(int k=n+1;s[k-1]<=x;k++){
        for(int j=k-n;j<=k-1;j++){
            s[k]+=s[j];
        }
        if(s[k]==x) return true;
        if(s[k]>x) return false;
    }
    return false;
}

int main(){
    for(int i=maxn;i>=0;i--){
        if(chk(i)){
            cout<<i;
            break;
        }
    }
    return 0;
}