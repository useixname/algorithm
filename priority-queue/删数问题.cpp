#include<bits/stdc++.h>
using namespace std;
const int N=3e4+10;
typedef pair<int,int>PII;
int n,k,a[N];
priority_queue<int,vector<int>,greater<> >q;
priority_queue<PII,vector<PII>,less<> >q1;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    q.push(1);
    cin>>n>>k;
    int l=1;
    while(l<=n){
        int x=q.top();
        s+=to_string(x);
        int y1=x*2+1,y2=x*4+5;
        q.push(y1);
        q.push(y2);
        q.pop();
        l++;
    }
    cout<<s<<'\n';
    int rest=s.size()-k;
    int L = 0,R = k,flag=0;
    int Maxx = 0;
    while(L <= R && R < s.length()){
        flag=1;
        for(int i = L ; i <= R ; i++){
    	    if((s[i] - '0') > Maxx) Maxx = (s[i] - '0') , L = i + 1;
	    }
	    cout<<Maxx;
	    R++;
	    Maxx = 0;
	}
    if(!flag) cout<<0;
    return 0;
}