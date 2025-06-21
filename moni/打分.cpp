#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1e5+10;
int a[N];
int n,m,s;

signed main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    sort(a+1,a+n+1);
    s-=a[1];
    int cnt=m,maxn=a[n];
    for(int i=2;i<=n-1;i++){
        cnt-=(a[n]-a[i]);
    }
    if(cnt<=0) printf("%llu",s+m-maxn);
    else{
        while(cnt>0){
            for(int i=2;i<=n;i++){
                a[i]=maxn;
                a[i]++;
                cnt--;
                if(a[i]>maxn) maxn=a[i];
                if(cnt==0) break;
            }
            if(cnt==0) break;
        }
        printf("%llu",s+m-maxn);
    }
    return 0;
}