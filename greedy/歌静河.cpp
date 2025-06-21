#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char a[N],b[N];
int n,m,cntb,k=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++){
        if(b[i]=='#') cntb++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='#'){
            a[i]=(k-1)%26+'a';
            if(cntb>=26-k){
                cntb-=(26-k);
                k=1;
            }
            else{
                k++;
            }
        }
    }
    cout<<a+1;
    return 0;
}