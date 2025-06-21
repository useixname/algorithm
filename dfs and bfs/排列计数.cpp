#include<bits/stdc++.h>
using namespace std;
string s,s1;
int ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    s1=s;
    sort(s.begin(),s.end());
    int n=s.size();
    while(s!=s1){
        next_permutation(s.begin(),s.end());
        ans++;
    }
    cout<<ans;
    return 0;
}