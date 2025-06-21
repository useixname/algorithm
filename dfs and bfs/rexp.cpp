#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

// (aaa)aa|aa|(a(aa)a)
int dfs(){
    int s=0,s1=0;
    char ch;
    while(cin>>ch){
        if(ch=='('){
            s+=dfs();
        }
        else{
            if(ch==')'){
                return s;
            }
            else if(ch=='a'){
                s++;
            }
            else{
                s1+=dfs();
                s=max(s,s1);
                return s;
            }
        }
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout<<dfs();
    return 0;
}