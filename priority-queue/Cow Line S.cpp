#include<bits/stdc++.h>
using namespace std;
int n,num=1;
deque<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--){
        char op,f;
        cin>>op>>f;
        if(op=='A'){
            if(f=='L') q.push_front(num++);
            else q.push_back(num++);
        }
        else{
            int k;
            cin>>k;
            if(f=='L'){
                for(int i=1;i<=k;i++) q.pop_front();
            }
            else{
                for(int i=1;i<=k;i++) q.pop_back();
            }
        }
    }
    for(auto it=q.begin();it!=q.end();it++){
        cout<<*it<<'\n';
    }
    // while(q.size()){
    //     cout<<q.front()<<'\n';
    //     q.pop_front();
    // }
    return 0;
}