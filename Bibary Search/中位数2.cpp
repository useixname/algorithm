#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>a;
int v[N],q[N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        a.push_back(v[i]);
    }
    a.push_back(0);//因为vector数组是从下标为0的位置开始访问的，所以要在前面添加一个数字。
    sort(a.begin(),a.end());
    int m;
    cin>>m;
    while(m--){
        int x;
        cin>>x;
        auto pos=lower_bound(a.begin(),a.end(),v[x]); 
        a.erase(pos);
        int len=a.size();
        if(!(len&1)){
            printf("%.1f ",a[(len+1)/2]*1.0);
        }
        else{
            printf("%.1f ",(a[len/2]+a[len/2+1])*1.0/2);
        }
    }
    return 0;
}