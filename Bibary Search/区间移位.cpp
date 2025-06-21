#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int n;
//存储区间:
struct st{
    int l,r;
};
vector<st> D;
//优先按右端点排序: 
bool cmp(st x,st y){
    if(x.r!=y.r)return x.r<y.r;
    else return x.l<y.l;
}
//验证答案:
bool check(int x){
    int t=0;
    vector<st> d(D);//复制一份用以删除用过的区间
    while(true){
    	bool flag=0;//找没找到
    	for(int i=0;i<d.size();i++){
    		if(d[i].l>t){//需要把区间左移
    			if(d[i].l-x<=t){//可以左移 
    				flag=1;
    				t+=d[i].r-d[i].l;
    				d.erase(d.begin()+i);//删除
                    i--;//删除后i要退1
					break; 
				}
			}else if(d[i].l==t){//区间左端点刚好是t点
				flag=1;
				t=d[i].r;
				d.erase(d.begin()+i);
                i--;
				break;
			}else{//区间已覆盖t点 
				flag=1;
				t=max(t,d[i].r+min(x,t-d[i].l));//让更新后的t点尽可能地右(但是受到最大位移和覆盖到点t的限制)
				d.erase(d.begin()+i);
                i--;
				break;
			}
		}
		if(flag==0||d.empty())break;
	}
	return t>=20000;
}

int binarySearch(){
    int l,r,mid;
    l=0,r=2*maxn;
    while(l+1<r){
        mid=l+(r-l)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1,dl,dr;i<=n;i++){
    	cin>>dl>>dr;
    	D.push_back({2*dl,2*dr});
	}
    sort(D.begin(),D.end(),cmp);
    cout<<binarySearch()/2.0;
    return 0;
}