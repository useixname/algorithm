#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n;

int find_mid(int a[],int low,int high){
    int bond=a[high];
    while(low<high){
        while(low<high&&a[low]<=bond) low++;
        a[high]=a[low];
        while(low<high&&a[high]>=bond) high--;
        a[low]=a[high];
    }
    a[low]=bond;
    return low;
}

void qsort(int a[],int l,int r){
    if(l<r){
        int mid=find_mid(a,l,r);
        qsort(a,l,mid-1);
        qsort(a,mid+1,r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
    qsort(a,1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}