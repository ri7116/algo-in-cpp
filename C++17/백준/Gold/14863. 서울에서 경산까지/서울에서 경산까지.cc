#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int dp[104][100004];
int a,b,c,d;

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d; // 시간 금액 시간 금액
        if(i==1){
            dp[1][a]=b;
            dp[1][c]=d;
        }
        else{
            for(int j=1;j<=k;j++){
                if(dp[i-1][j]!=0){
                    dp[i][j+a]=max(dp[i][j+a],dp[i-1][j]+b);
                    dp[i][j+c]=max(dp[i][j+c],dp[i-1][j]+d);
                }
            }
        }
    }
    
    int ans=0;
    for(int j=1;j<=k;j++){
    //    cout<<dp[n][j]<<endl;
        if(dp[n][j]!=0){
            ans=max(ans, dp[n][j]);
        }
    }
    cout<<ans;
}

//1. DP
//2. N * K = 100 * 100000 = 10000000  => 천만이므로 계산이 무조건 가능함.