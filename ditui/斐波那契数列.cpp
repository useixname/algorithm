#include<bits/stdc++.h>
using namespace std;
double f[4];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[3]=f[1]+f[2];
        f[1]=f[2];
        f[2]=f[3];
    }
    printf("%.2f",f[3]);
    return 0;
}