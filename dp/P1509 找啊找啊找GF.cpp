#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=110;
vector<vector<PII>>f(N,vector<PII>(N,{0,0}));
int n,m,r;
int rmb[N],rp[N],times[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>rmb[i]>>rp[i]>>times[i];
    }
    cin>>m>>r;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=rmb[i];j--){
            for(int k=r;k>=rp[i];k--){
                if(f[j][k].first<f[j-rmb[i]][k-rp[i]].first+1||
                f[j][k].first==f[j-rmb[i]][k-rp[i]].first+1&&f[j][k].second>f[j-rmb[i]][k-rp[i]].second+times[i]){
                    f[j][k].first=f[j-rmb[i]][k-rp[i]].first+1;
                    f[j][k].second=f[j-rmb[i]][k-rp[i]].second+times[i];
                }
            }
        }
    }
    int bestc=0,besttime=0x7fffffff;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=r;j++){
            int c=f[i][j].first,t=f[i][j].second;
            if(c>bestc){
                bestc=c;
                besttime=t;
            }
            else if(c==bestc&&t<besttime){
                besttime=t;
            }
        }
    }
    cout<<besttime;
    return 0;
}