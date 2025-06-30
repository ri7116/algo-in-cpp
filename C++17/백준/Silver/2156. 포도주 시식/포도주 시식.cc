#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10004];
int dp[10004][4][4];
int w(int n,int e, int r){
    // 메모이제이션: 이미 계산된 값이면 바로 반환
    if(dp[n][e][r] != -1) return dp[n][e][r];
    
    if(n==1 and r==1) return dp[n][e][r] = arr[1];
    if(n==1 and r==0) return dp[n][e][r] = 0;

    // if(n==2 and e==2) return arr[2]+arr[1];
    // if(n==2 and e==1) return arr[2];
    // if(n==2 and e==0) return arr[1];

    if(e==2) return dp[n][2][1]=w(n-1,1,1)+arr[n];
    
    if(e==1) return dp[n][1][1]=w(n-1,0,0)+arr[n];

    if(e==0) return dp[n][0][0]=max(max( w(n-1,1,1) , w(n-1,2,1) ) ,w(n-1,0,0)); 
}


int main(){
    // dp 배열을 -1로 초기화 (아직 계산되지 않았음을 의미)
    memset(dp, -1, sizeof(dp));
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    w(n,2,1);
    w(n,1,1);
    w(n,0,0);
    cout<<max(max(dp[n][2][1],dp[n][1][1]),dp[n][0][0]);
}
//좌항이 우항보다 커야됨