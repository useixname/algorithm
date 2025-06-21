#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
	char c;
	while((c=getchar())<48||c>57);
	int ret=c-48;
	while((c=getchar())>47&&c<58) ret=ret*10+c-48;
	return ret;
}
struct edge{
    int x,y;
};
int n,m,cnt,pre[200];
vector<int> g[200];
vector<edge> ans;
int dfs(int u,int fa){
    int lowu=pre[u]=++cnt;
    for(auto v:g[u])
    	if(!pre[v]){
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>pre[u]) ans.push_back(u>v?edge{v,u}:edge{u,v});
        }else if(pre[v]<pre[u]&&v!=fa) lowu=min(lowu,pre[v]);
    return lowu;
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
        int x=read(),y=read();
        g[x].push_back(y);
        g[y].push_back(x);
	}
	dfs(1,-1);
	sort(ans.begin(),ans.end(),[&](const edge& a,const edge& b){return a.x<b.x||a.x==b.x&&a.y<b.y;});
	for(auto i:ans) printf("%d %d\n",i.x,i.y);
	return 0;
}