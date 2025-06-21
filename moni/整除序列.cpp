#include<cstdio>
#include<algorithm>
#define int long long
int n;

signed main(){
    scanf("%lld",&n);
    printf("%lld",n);
    while(n>1){
        printf(" %lld",n/2);
        n/=2;
    }
    return 0;
}