#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int f[N];
int l,r;

void init(){
    for(int i=1;i<=1e3;i++){
        int x=i*i;
        f[x]=1;
    }
}

bool chk(int x){
    if(!f[x]) return false;
    string s=to_string(x);
    int n=s.size();
    for(int i=1;i<n;i++){
        int x1=stoi(s.substr(0,i));
        int x2=stoi(s.substr(i));
        if(f[x1]&&f[x2]) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    init();
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if(chk(i)) cout<<i<<'\n';
    }
    return 0;
}