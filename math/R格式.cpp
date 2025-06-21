#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
string s;
int n,l;

void mul(){
    for(int i=1;i<=l;i++){
        a[i]*=2;
    }
    for(int i=1;i<=l;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[l+1]){
        l++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    reverse(s.begin(),s.end());
    int p=s.find(".");
    s.erase(p,1);
    l=s.size();
    for(int i=1;i<=l;i++){
        a[i]=s[i-1]-48;
    }
    for(int i=1;i<=n;i++){
        mul();
    }
    if(a[p]>=5){
        a[p+1]++;
    }
    for(int i=p+1;i<=l;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[l+1]){
        l++;
    }
    for(int i=l;i>p;i--){
        cout<<a[i];
    }
    return 0;
}