#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int f[N];
int a,b;

void init(){
    for(int i=1;i<=1000;i++){
        f[i*i]=1;
    }
}

bool chk(int x){
    if(!f[x]) return false;
    string s=to_string(x);
    int n=s.size();
    for(int i=1;i<n;i++){
        int a=stoi(s.substr(0,i));
        int b=stoi(s.substr(i));
        if(f[a]&&f[b]) return true;
    }
    return false;
}

int main(){
    init();
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(chk(i)) cout<<i<<'\n';
    }
    return 0;
}