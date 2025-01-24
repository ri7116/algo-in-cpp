#include<bits/stdc++.h>
using namespace std;
int n, k;
int coin[104];
int dp[100004];

int main(){
  cin>>n>>k;
  for(int i=1;i<=n;i++){//1부터 받는게 중요함
    int a;
    cin>>a;
    coin[i]=a;
  }
    dp[0]=1;
   
  for(int i=1;i<=n;i++){//코인 시작
    for(int j=coin[i];j<=k;j++){
      dp[j]+=dp[j-coin[i]];
    }
  }
  cout<<dp[k];
}
//거의 3시간 걸림.. dp[i][j] i번까지의 모든 종류의 코인을 사용하여 최대한 만들 수 있는 합이 j인 경우의 수