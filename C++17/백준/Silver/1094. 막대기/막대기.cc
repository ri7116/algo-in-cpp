#include<bits/stdc++.h>
using namespace std;

int X;


int main(){
    cin>>X;
    int ans=0;
    for(int i=0;i<7;i++){
        if(X & 1<<i) ans++;
    }
    cout<<ans;
}
//1. 사용할 수 있는 수는 1 2 4 8 16 32 64임! => 비트마스킹