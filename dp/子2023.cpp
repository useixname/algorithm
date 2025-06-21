#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int f[4];
//f[i]表示以第i个数为结尾的序列个数

signed main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=2023;i++){
        s+=to_string(i);
    }
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='2'){
            f[0]++;
            f[2]+=f[1];
        }
        if(s[i]=='0'){
            f[1]+=f[0];
        }
        if(s[i]=='3'){
            f[3]+=f[2];
        }
    }
    cout<<f[3];
    return 0;
}