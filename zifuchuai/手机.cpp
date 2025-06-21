#include<bits/stdc++.h>
using namespace std;
const int N=256;
char s[N];
map<char,int>m;
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.get(s+1,256);
    m={{'a',1},{'b',2},{'c',3},{'d',1},{'e',2},{'f',3},{'g',1},{'h',2},
       {'i',3},{'j',1},{'k',2},{'l',3},{'m',1},{'n',2},{'o',3},{'p',1},
       {'q',2},{'r',3},{'s',4},{'t',1},{'u',2},{'v',3},{'w',1},{'x',2},
       {'y',3},{'z',4},{' ',1}};
    for(int i=1;i<=strlen(s+1);i++){
        ans+=m[s[i]];
    }
    cout<<ans;
    return 0;
}