#include<bits/stdc++.h>
using namespace std;
int t;
int a2,a3,a4,b4,b6;

int solve(){
    int result = 0;
    while (a3 > 1 && b6 > 0) { a3 -= 2; b6--; result += 6; }
    while (a4 > 0 && a2 > 0 && b6 > 0) { a2--; a4--; b6--; result += 6; }
    while (a2 > 2 && b6 > 0) { a2 -= 3; b6--; result += 6; }
    while (a3 > 0 && a2 > 0 && b6 > 0) { a3--; a2--; b6--; result += 5; }
    while (a4 > 0 && b6 > 0) { a4--; b6--; result += 4; }
    while (a2 > 1 && b6 > 0) { a2 -= 2; b6--; result += 4; }
    while (a3 > 0 && b6 > 0) { a3--; b6--; result += 3; }
    while (a2 > 0 && b6 > 0) { a2--; b6--; result += 2; }
    while (a4 > 0 && b4 > 0) { a4--; b4--; result += 4; }
    while (a2 > 1 && b4 > 0) { a2 -= 2; b4--; result += 4; }
    while (a3 > 0 && b4 > 0) { a3--; b4--; result += 3; }
    while (a2 > 0 && b4 > 0) { a2--; b4--; result += 2; }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>a2>>a3>>a4>>b4>>b6;
        cout<<solve()<<'\n';
    }
    return 0;
}