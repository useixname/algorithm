#include<bits/stdc++.h>
using namespace std;
int ans;
int m[10]={13,1,2,3,5,4,4,2,2,2};
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool chk(int y){
    if((y%4==0&&y%100!=0)||(y%400==0&&y%100==0)){
        return true;
    }
    return false;
}

int main(){
    for(int y=2000;y<=2023;y++){
        if(chk(y)){
            a[2]=29;
        }
        else{
            a[2]=28;
        }
        for(int i=1;i<=12;i++){
            for(int j=1;j<=a[i];j++){
                int cnt=m[y%10]+m[(y/10)%10]+m[(y/100)%10]+m[y/1000]+m[i%10]+m[i/10]+m[j%10]+m[j/10];
                if(cnt>50) ans++;
            }
        }
    }
    a[2]=29;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=a[i];j++){
            int cnt=m[2]+m[0]+m[2]+m[4]+m[i%10]+m[i/10]+m[j%10]+m[j/10];
            if(cnt>50) ans++;
        }
    }
    for(int j=1;j<=13;j++){
        int cnt=m[2]+m[0]+m[2]+m[4]+m[0]+m[4]+m[j%10]+m[j/10];
        if(cnt>50) ans++;
    }
    cout<<ans;
    return 0;
}