#include<bits/stdc++.h>
using namespace std;
int dp[1000004];


int main(){
    int n;
    int tmp=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        dp[a]=dp[a-1]+1;
        tmp=max(tmp,dp[a]);
    }
    
    cout<<n-tmp;
}
// 기존의 LIS면 n^2이라 못 푸는 거 같은데?
// 1차이의 LIS를 구해야 함.