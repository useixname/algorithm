#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int diff[N][N];
int n,m;

void insert(int x1,int y1,int x2,int y2,int c){
    diff[x1][y1]+=c;
    diff[x2+1][y1]-=c;
    diff[x1][y2+1]-=c;
    diff[x2+1][y2+1]+=c;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        insert(x1,y1,x2,y2,1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            cout<<diff[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}