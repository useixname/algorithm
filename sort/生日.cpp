#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;

struct node{
    string name;
    int y,m,d,k;
    bool operator<(const node &pa) const{
        if(y==pa.y&&d==pa.d&&m==pa.m){
            return k>pa.k;
        }
        if(y!=pa.y){
            return y<pa.y;
        }
        else{
            if(m!=pa.m){
                return m<pa.m;
            }
            else{
                return d<pa.d;
            }
        }
    }
}a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].name>>a[i].y>>a[i].m>>a[i].d;
        a[i].k=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cout<<a[i].name<<'\n';
    }
    return 0;
}