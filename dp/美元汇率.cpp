#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
double f[N][2];
int n;
double a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[1][0]=100,f[1][1]=a[1];
    for(int i=2;i<=n;i++){
        f[i][0]=max(f[i-1][1]/(a[i]/100),f[i-1][0]);
        f[i][1]=max(f[i-1][0]*(a[i]/100),f[i-1][1]);
    }
    printf("%.2f",f[n][0]);
    return 0;
}