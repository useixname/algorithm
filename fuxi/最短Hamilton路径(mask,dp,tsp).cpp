#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=21;
int f[1<<N][N],dist[N][N];
int n,ans=inf;;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    memset(f,inf,sizeof(f));
    //初始化
    f[1<<(1-1)][1]=0;
    //遍历已经走过的点
    for(int mask=1;mask<(1<<n);mask++){
        //遍历当前所在的点
        for(int k=1;k<=n;k++){
            //如果当前点不在mask当中,跳过
            if((mask&(1<<(k-1)))==0) continue;
            //如果当前花费为无穷大,跳过
            if(f[mask][k]==inf) continue;
            //遍历要去的点
            for(int j=1;j<=n;j++){
                //如果要去的点已经走过,跳过
                if((mask&(1<<(j-1)))!=0) continue;
                //把要去的点加入已经走过的点的集合中
                int new_mask=mask|(1<<(j-1));
                //状态转移
                f[new_mask][j]=min(f[new_mask][j],f[mask][k]+dist[k][j]);
            }
        }
    }
    //在全集中即所有的点都到达的集合中遍历最后到达的点
    int full_mask=(1<<n)-1;
    for(int k=1;k<=n;k++){
        ans=min(ans,f[full_mask][n]);
    }
    cout<<ans;
    return 0;
}
//要强制从节点 1 出发并且以节点 n 为终点，只需对状态初始化和答案取值做以下两点修改：
//1.只把 “刚访问节点 1” 这一个状态初始化为 0，而不再对所有节点都初始化。
//2.最终答案只取 “完整子集(1…n)，且最后在 n”，而不是对所有 k 都取最小。