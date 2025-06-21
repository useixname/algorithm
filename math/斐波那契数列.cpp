#include<cstdio>
int n,ans;
long long tx,ty,fx,fy,sx,sy;
int main(){
    scanf("%d",&n);
    for(int p0=1, p1=1, x=0, y=1; p0+p1<=n; p1=p0+p1, p0=p1-p0, x=y-x, y=y-x){
        tx=1ll*x*n, ty=1ll*y*n;
        fx=tx%p1; if(fx<=0) fx+=p1; fy=ty-(fx-tx)/p1*p0;
        sy=ty%p0; if(sy<=0) sy+=p0; sx=tx-(sy-ty)/p0*p1;
        if(fy<=0||sx<=0) break;
        ans=(ans+(sx-fx)/p1+1)%1000000007;
    }
    printf("%d",ans);
}