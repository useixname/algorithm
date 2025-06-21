#include<bits/stdc++.h>
using namespace std;
const int N=4e4+10;
bool f[N];
struct node{
    int h,a,c;
    bool operator<(const node & pa) const{
        return a<pa.a;
    }
}b[410];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].h>>b[i].a>>b[i].c;
    }
    sort(b+1,b+n+1);
    f[0]=true;
    //f[k]表示能否使用这n种方块到达高度k
    for(int i=1;i<=n;i++){  //总的物品个数
        for(int j=1;j<=b[i].c;j++){     //每一个物品个数
            for(int k=b[i].a;k>=b[i].h;k--){    //背包容量
                f[k]|=f[k-b[i].h];
            }
        }
    }
    for(int i=b[n].a;i>=0;i--){
        if(f[i]){
            cout<<i;
            return 0;
        }
    }
    return 0;
}