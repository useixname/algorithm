#include<bits/stdc++.h>
using namespace std;
int a[85][10000];
int n,m,k,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    cin>>k;
    // 枚举上边界
    for(int top=1;top<=n;top++){
        vector<int> colMin(m+1, INT_MAX), colMax(m+1, 0);
        // 枚举下边界
        for(int bottom=top;bottom<=n;bottom++){
            // 更新每一列的最值
            for(int j=1;j<=m;j++){
                colMax[j]=max(colMax[j],a[bottom][j]);
                colMin[j]=min(colMin[j],a[bottom][j]);
            }
            deque<int>d_max,d_min;
            int l=1;
            // 枚举右边界
            for(int r=1;r<=m;r++){
                while(!d_max.empty()&&colMax[r]>=colMax[d_max.back()]){
                    d_max.pop_back();
                }
                d_max.push_back(r);

                while(!d_min.empty()&&colMin[r]<=colMin[d_min.back()]){
                    d_min.pop_back();
                }
                d_min.push_back(r);

                while(!d_max.empty()&&!d_min.empty()&&colMax[d_max.front()]-colMin[d_min.front()]>k){
                    if(d_max.front()==l) d_max.pop_front();
                    if(d_min.front()==l) d_min.pop_front();
                    l++;
                }
                ans=max(ans,(bottom-top+1)*(r-l+1));
            }
        }
    }
    cout<<ans;
    return 0;
}