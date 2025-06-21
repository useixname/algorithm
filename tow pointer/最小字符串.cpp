#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,m;

int main(){
    cin>>n>>m;
    cin>>s1>>s2;
    sort(s2.begin(),s2.begin()+m);
    int i=0,j=0;
    while(i<n&&j<m){
        if(s1[i]<=s2[j]) cout<<s1[i++];
        if(s1[i]>s2[j]) cout<<s2[j++];
    }
    while(i<n) cout<<s1[i++];
    while(j<m) cout<<s2[j++];
    return 0;
}