#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
map<PII,int>m,vis;
int n,ans;

int gcd(int a,int b){
    if(b==0) return a;
    if(a%b==0){
        return  b;
    }
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int dx=abs(x1-x2),dy=abs(y1-y2);
        int g=gcd(dx,dy);
        dx=(x2-x1)/g;
        dy=(y2-y1)/g;
        while(x1!=x2||y1!=y2){
            m[{x1,y1}]++;
            if(m[{x1,y1}]>=2&&!vis[{x1,y1}]){
                vis[{x1,y1}]=1;
                cout<<x1<<" "<<y1<<'\n';
                ans++;
            }
            x1+=dx;
            y1+=dy;
        }
        m[{x2,y2}]++;
        if(m[{x2,y2}]>=2&&!vis[{x2,y2}]){
            vis[{x2,y2}]=1;
            cout<<x2<<" "<<y2<<'\n';
            ans++;
        }
    }
    cout<<ans;
    return 0;
}