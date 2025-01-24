#include<bits/stdc++.h>
using namespace std;
int n, k;
vector <int> coins;
vector <int> dp;

int main(){
  cin>>n>>k;
  coins.resize(n+1);
  dp.resize(k+1);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    coins[i]=a;
  }
  for(int i=0;i<k+1;i++){
    dp[i]=123456789;
  }
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=coins[i];j<=k;j++){
      dp[j]=min(dp[j-coins[i]]+1, dp[j]);
    }
  }
  if(dp[k]==123456789) cout<<-1;
  else cout<<dp[k];
}
//dp 식 부분이 어렵네..