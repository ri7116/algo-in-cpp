#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100004];
int arr[100004];
int mx=-1;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    for(int i=0;i<n;i++){
        dp[i]=1;
        //i=0 j=0 발동?
        for(int j=0;j<i;j++){
            //cout<< i<<" "<<j<<endl;
            if(arr[i]>arr[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        //cout<<dp[i]<<endl;
        mx=max(mx,dp[i]);
    }
    //cout<<dp[n-1]<<endl;
    cout<<n-mx;
}
//! dp[i]는 그 위치를 포함한 최대 길이
//! dp[i]라고 해서 최대 길이인 것이 아님, 중간이 최대일 수 있는겨
//1. dp 최장 증가 부분 수열문제