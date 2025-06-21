#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n;
double a[N];

double f(double x){
    double ret=0;
    for(int i=n;i>=0;i--){
        ret+=pow(x,i)*a[n-i+1];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    double l,r;
    cin>>n>>l>>r;
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    while(r-l>1e-5){
        double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
        if(f(mid1)<f(mid2)) l=mid1;
        else r=mid2;
    }
    printf("%.5f",l);
    return 0;
}