#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int n;
char a[N];

string mul(int x,string s){
    string ret="";
    for(int i=1;i<=x;i++){
        ret.append(s);
    }
    return ret;
}

string add(int x,int &e){
    string ret="";
    int i=x;
    while(a[i]>='A'&&a[i]<='Z'&&i<=n){
        ret+=a[i];
        i++;
    }
    e=i;
    return ret;
}
// [2[2[2CB]]]
// AC[3FUN]
string dfs(int x,int y){
    if(x>y) return "";
    string ret="";
    if(a[x]=='['){
        ret.append(dfs(x+1,y-1));
        return ret;
    }
    else if(a[x]>='1'&&a[x]<='9'){
        if(a[x+1]>='1'&&a[x+1]<='9'){
            int num=(a[x]-'0')*10+(a[x+1]-'0');
            ret.append(mul(num,dfs(x+2,y)));
        }
        else{
            ret.append(mul(a[x]-'0',dfs(x+1,y)));
        }
        return ret;
    }
    else{
        int e=-1;
        ret.append(add(x,e));
        if(e!=-1){
            ret.append(dfs(e,y));
        }
        return ret;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>a+1;
    n=strlen(a+1);
    cout<<dfs(1,n);
    return 0;
}