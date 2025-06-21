#include<bits/stdc++.h>
using namespace std;
stack<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    int x;
    cin>>x;
    while(x!=0){
        s.push(x);
        cin>>x;
    }
    while(s.size()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}