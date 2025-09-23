#include<bits/stdc++.h>
using namespace std;
long long n, result;
long long arr[104];
long long dp[104][24];


int main(){
    cin>>n;
    
    for(int i=1;i<=n;i++){
        if(i!=n) cin>>arr[i];
        else cin>>result;
    }

    dp[1][arr[1]]++;

    for(int i=2;i<n;i++){
        for(int j=0;j<=20;j++){
            if(dp[i-1][j]!=0 and (0<=j+arr[i] and j+arr[i]<=20)) dp[i][j+arr[i]]+=dp[i-1][j];
            if(dp[i-1][j]!=0 and (0<=j-arr[i] and j-arr[i]<=20)) dp[i][j-arr[i]]+=dp[i-1][j];
            // dp[i][j-arr[i]]=dp[i-1][j]+1// 이건 몇 단계를 거쳤느냐를 저장하는 거임!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }

    cout<<dp[n-1][result];
}
//1. dp 점화식을 잘 구분해보자 점화식 분석 필수임!