#include <bits/stdc++.h>
#define int long long
#define ll long long
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define endl "\n"
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int l,r,n,A;
int a[2][200005];//a[0][]用来记录L,a[1][]用来记录R 
int f[200005][20];//dp数组  f[i][j] 表示到第i位且此时非重复的位数为j时的答案
int kk[20];//kk[i]表示i出现了几次
int mod=1e9+7;//题目要求的取模
int dfs(int x,int sum,int falt,int dd,int k){
	//x为目前遍历到哪一位
	//sum表示此时非重复的位数
	//falt为1时表示有上界限制
	//dd为1时表示有前导0
	//k=0时表示此时求得是L,k=1时表示此时求得是R
	
	if(x>n){//遍历完了 退出
		return sum==A;
	}
	
	//记忆化 利用已计算出的答案 用于提速
	if(!falt&&!dd&&f[x][sum]!=-1) return f[x][sum];
	
	int mx=9;//此时这一位的上界
	if(falt) mx=a[k][x];//有上界限制为a[k][x] 无上界限制为9
	
	int res=0;
	for(int i=0;i<=mx;i++){//遍历这一位的所有取值
		
		if(dd&&i==0){//前面是前导0且这一位也为0，无贡献，直接继续往下dfs
			res+=dfs(x+1,sum,falt,dd,k);
			res=res%mod;//注意取模
		}else{
			kk[i]++;//此时选i
			int nm=0;
			if(kk[i]==1) nm=1;//如果i第一次被选
			res+=dfs(x+1,sum+nm,falt&&(i==mx),dd&&i==0,k);
			res=res%mod;//注意取模
			kk[i]--;//回溯置0
		}
	}
	
	//无限制条件才可放入，对应上面的记忆化
	if(!falt&&!dd) f[x][sum]=res;
	
	return res;
}
 
int find(int k){
	int ans=0;
	memset(&f,-1,sizeof f);//记得初始化
	
	for(int i=0;i<=a[k][1];i++){//枚举第一位
		kk[i]=1;
		ans=(ans+dfs(2,1,i==a[k][1],i==0,k))%mod;
		kk[i]=0;
	}
	return 	ans;
}
signed main(){
	FAST
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){//输入L
		cin>>c;
		a[0][i]=c-'0';
	}
	for(int i=1;i<=n;i++){//输入R
		cin>>c;
		a[1][i]=c-'0';
	}
	cin>>A;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){//特判L是否满足
		kk[a[0][i]]++;
		if(kk[a[0][i]]==1){
			sum++;
		}
	}
	if(sum==A) ans++;
	for(int i=0;i<=9;i++) kk[i]=0;
	
    //ans2-ans1+特判L   恭喜你成功ac
	cout<<(find(1)-find(0)+ans+mod)%mod<<endl;
	return 0;
}