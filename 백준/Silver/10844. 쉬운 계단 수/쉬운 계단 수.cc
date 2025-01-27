#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
int N;
int dp[104][14];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=1;i<=9;i++){
    dp[1][i]=1;
  }
  cin >> N;
  for(int i=2;i<=N;i++){
    for(int j=0;j<=9;j++){
      if(j==0){
        dp[i][j]=dp[i-1][j+1]%mod;
      }
      else if(j==9){
        dp[i][j]=dp[i-1][j-1]%mod;
      }
      else{
        dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % mod;
      }
    }
  }
  int ans=0;
  for(int i=0;i<=9;i++){
    ans= (ans + dp[N][i]) %mod;
  }
  cout<<ans%mod;
}