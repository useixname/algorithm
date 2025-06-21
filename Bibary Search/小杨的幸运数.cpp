#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int lucky[N],b[N],k;
int a,n;

void get_lucky(){
    int start=ceil((double) sqrt(a));
    for(int i=start;i*i<=N;i++){
        int k=i*i;
        if(!lucky[k]){
            for(int j=k;j<=N;j+=k){
                lucky[j]=1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>n;
    get_lucky();
    for(int i=1;i<=N;i++){
        if(lucky[i]) b[++k]=i;
    }
    while(n--){
        int x;
        cin>>x;
        if(lucky[x]) cout<<"lucky"<<'\n';
        else{
            cout<<b[upper_bound(b+1,b+k,x)-b]<<'\n';
        }
    }
    return 0;
}