#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
unordered_map<int,string>mp1,mp2;
int f[N][N];
string s1,s2;
int l1,l2;

void zh(string s,int & l,unordered_map<int,string>& mp){
    int n=s.size();
    int b[n+1];
    for(int i=1;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            b[++l]=i;
        }
    }
    int st=0;
    // LqqqB
    // 01234
    b[++l]=n;
    for(int i=1;i<=l;i++){
        string t=s.substr(st,b[i]-st);
        mp[i]=t;
        st=b[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s1>>s2;
    zh(s1,l1,mp1);zh(s2,l2,mp2);
    // for(int i=1;i<=l1;i++){
    //     cout<<mp1[i]<<" ";
    // }
    // for(int i=1;i<=l2;i++){
    //     cout<<mp2[i]<<" ";
    // }
    f[0][0]=0;
    for(int i=1;i<=max(l1,l2);i++){
        f[i][i]=1;
    }
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(mp1[i]==mp2[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
            else{
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[l1][l2];
    return 0;
}