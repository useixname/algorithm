#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
unordered_map<int,string>mp;
vector<string>a,ans;
int f[N],b[N],pre[N];
string s;
int cnt;

//AaaaAaa
//0123456
void zh(string s){
    int l=s.size();
    int st=0;
    for(int i=1;i<l;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            mp[++cnt]=s.substr(st,i-st);
            a.push_back(s.substr(st,i-st));
            st=i;
        }
    }
    mp[++cnt]=s.substr(st,l-st);
    a.push_back(s.substr(st,l-st));
}

bool cmp(string s1,string s2){
    return s1<s2;
    // int l1=s1.size();
    // for(int i=0;i<l1;i++){
    //     if(s1[i]>s2[i]) return false;
    // }
    // return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    zh(s);
    sort(a.begin(),a.end());
    for(int i=1;i<=cnt;i++){
        int pos=lower_bound(a.begin(),a.end(),mp[i])-a.begin();
        b[i]=pos+1;
    }
    // for(string t:a){
    //     cout<<t<<" ";
    // }
    // cout<<'\n';
    // for(int i=1;i<=cnt;i++){
    //     cout<<b[i]<<" ";
    // }
    int maxn=0,index=0;
    for(int i=1;i<=cnt;i++){
        f[i]=1;
        pre[i]=0;
        for(int j=1;j<i;j++){
            if(b[j]<b[i]&&f[i]<=f[j]+1){
                f[i]=f[j]+1;
                pre[i]=j;
            }
        }
        if(f[i]>=maxn){
            maxn=f[i];
            index=i;
        }
    }
    // cout<<'\n';
    while(index){
        // cout<<index<<" ";
        ans.push_back(mp[index]);
        index=pre[index];
    }
    int n=ans.size();
    for(int i=n-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}
//5 1 3 4 2