#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n;

void qsort(int l,int r){
    if(l>=r) return;

    int i=l-1,j=r+1,k=a[(l+r)>>1];
    while(i<j){
        do i++; while(a[i]<k);
        do j--; while(a[j]>k);
        if(i<j) swap(a[i],a[j]);
    }
    qsort(l,j);qsort(j+1,r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    qsort(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}