#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N],b[N],c[N];
int la,lb,lc;
string s1,s2;

void add(){
    for(int i=1;i<=lc;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[lc+1]) lc++;
    for(int i=lc;i>=1;i--){
        cout<<c[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s1>>s2;
    la=s1.size();
    lb=s2.size();
    lc=max(la,lb);
    for(int i=0;i<la;i++){
        a[i+1]=s1[la-i-1]-'0';
    }
    for(int i=0;i<lb;i++){
        b[i+1]=s2[lb-i-1]-'0';
    }
    add();
    return 0;
}