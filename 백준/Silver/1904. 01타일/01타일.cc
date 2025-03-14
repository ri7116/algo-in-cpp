#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1000004];




int main(){
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<1000001;i++){
        dp[i]=(dp[i-1]+dp[i-2])%15746;
    }
    cout<<dp[n];
}
