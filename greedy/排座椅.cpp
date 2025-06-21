#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
struct node{
    int x,n;
}x[N],y[N];
int n,m,k,l,d;

bool cmp1(node x,node y){
    return x.n>y.n;
}

bool cmp2(node x,node y){
    return x.x<y.x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k>>l>>d;
    for(int i=1;i<=d;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2){
            int ny=min(y1,y2);
            y[ny].x=ny;
            y[ny].n++;
        }
        if(y1==y2){
            int nx=min(x1,x2);
            x[nx].x=nx;
            x[nx].n++;
        }
    }
    sort(x+1,x+1+N,cmp1);
    sort(y+1,y+1+N,cmp1);
    sort(x+1,x+1+k,cmp2);
    sort(y+1,y+1+l,cmp2);
    for(int i=1;i<=k;i++){
        cout<<x[i].x<<" ";
    }
    cout<<'\n';
    for(int i=1;i<=l;i++){
        cout<<y[i].x<<" ";
    }
    return 0;
}