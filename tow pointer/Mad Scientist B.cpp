#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char a[N],b[N];
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            ans++;
            int j=i+1;
            while(a[j]!=b[j]){
                j++;
            }
            i=j;
        }
    }
    cout<<ans;
    return 0;
}