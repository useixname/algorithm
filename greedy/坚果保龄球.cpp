#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,ans;
vector<int>a[7];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i=1;i<=6;i++){
        if(!a[i].empty()){
            ans++;
            sort(a[i].begin(),a[i].end());
            int t=a[i][0];
            for(int j=1;j<a[i].size();j++){
                if(a[i][j]-t>=60){
                    ans++;
                    t=a[i][j];
                }
            }
        }
    }
    cout<<ans;
    return 0;
}