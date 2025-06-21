#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int n,la,lb,lc;

void add(int b[]){
    for(int i=1;i<=lb;i++){
        c[i]+=b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[lc+1]) lc++;
}

void mul(int a[]){
    lb=2*la;
    for(int i=1;i<=la;i++){
        for(int j=1;j<=la;j++){
            b[i+j-1]=a[i]*a[i];
        }
    }
    for(int i=1;i<=lc;i++){
        b[i+1]+=b[i]/10;
        b[i]%=10;
    }
    while(lc>1&&b[lc]==0) lc--;
}

int main(){
    cin>>n;
    a[1]=6;
    la=1;
    for(int i=1;i<=n;i++){
        mul(a);
        add(b);
    }
    for(int i=lc;i>=1;i--){
        cout<<c[i];
    }
    cout<<0;
}