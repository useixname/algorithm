#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
char s[N];
int m[27],ans;

int main(){
    ios_base::sync_with_stdio(0);
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        int x=s[i]-'a'+1;
        m[x]++;
    }
    sort(m+1,m+27);
    cout<<m[26];
    return 0;
}