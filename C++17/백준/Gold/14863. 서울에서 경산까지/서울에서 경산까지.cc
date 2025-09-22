#include<bits/stdc++.h>
using namespace std;
long long n;
long long k;
long long dp[104][100004];
long long a,b,c,d;

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d; // 시간 금액 시간 금액
        if(i==1){
            dp[1][a]=max(dp[1][a],b);
            dp[1][c]=max(dp[1][c],d);
        }
        else{
            for(int j=1;j<=k;j++){
                if(dp[i-1][j]!=-1){
                    if(j+a<=k) dp[i][j+a]=max(dp[i][j+a],dp[i-1][j]+b);
                    if(j+c<=k) dp[i][j+c]=max(dp[i][j+c],dp[i-1][j]+d);
                }
            }
        }
    }

    long long ans=0;
    for(int j=1;j<=k;j++){
    //    cout<<dp[n][j]<<endl;
        if(dp[n][j]!=-1){
            ans=max(ans, dp[n][j]);
        }
    }
    cout<<ans;
}