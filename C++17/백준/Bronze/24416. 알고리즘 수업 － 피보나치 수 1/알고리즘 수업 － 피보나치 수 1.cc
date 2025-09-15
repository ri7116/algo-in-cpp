#include<bits/stdc++.h>
using namespace std;
int cnt1,cnt2;
int n;
int dp[10000000];

int fuc1(int n){
    if(n==1 or n==2) {
        cnt1++;
        return 1;
    }
    return fuc1(n-1)+fuc1(n-2);
}

int fuc2(int n){
    dp[1]=1;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        dp[n]=dp[n-1]+dp[n-2];
        cnt2++;
    }
    return dp[n];
}

int main(){
    cin>>n;
    fuc1(n);
    fuc2(n);
    cout<<cnt1<<" "<<cnt2;
}