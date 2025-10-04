#include<bits/stdc++.h>
using namespace std;
long long arr[10]={0,0,1,7,4,2,0,8};
long long dp[105];
int k;
int n;




int main(){
    cin>>k;
    // for(int i=0;i<=104;i++){
    //     dp[i]=21000000000000;
    // }
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=6;
    dp[7]=8;
    dp[8]=10;
    for(int i=9;i<=104;i++){
        for(int j=2;j<=7;j++){
            // dp[i]=min(dp[i-j]*10+arr[j],dp[i]);
            if(j==2) dp[i]=dp[i-j]*10+arr[j];
            else dp[i]=min(dp[i-j]*10+arr[j],dp[i]);
        }
    }
    while(k--){
        cin>>n;
        cout<<dp[n]<<" ";
        if(n%2==0){//짝수
            for(int i=0;i<n/2;i++){
                if(i==0) cout<<1;
                else cout<<1;
            }
        }
        else{//홀수
            for(int i=0;i<n/2;i++){
                if(i==0) cout<<7;
                else cout<<1;
            }
        }
        cout<<endl;
    }
}
//DP + 반복문은 처음이네
//최대값 출력에서 자릿수 문제가 생기네; 바로 출력 방식으로 넘어갈줄은 몰랐다.