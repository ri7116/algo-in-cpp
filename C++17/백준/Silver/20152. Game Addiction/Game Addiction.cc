#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p, h, dp[400][400];

int main(){ 
    cin>>h>>p;
    if(p==h){
        cout<<1;
        return 0;
    }

    if(p<h){
        for(int i=h;i>=p;i--){
            dp[i][h]=1;
        }

        for(int i=h;i>=p;i--){
            for(int j=h;j>=p;j--){
                if(i<=j and (i!=h and j!=h)) dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
    }
    else{
        for(int i=h;i<=p;i++){
            dp[h][i]=1;
        }

        for(int i=h;i<=p;i++){
            for(int j=h;j<=p;j++){
                if(i<=j and (i!=h and j!=h)) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[p][p];
    // for(int i=0;i<30;i++){
    //     for(int j=0;j<30;j++){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
}
// dp에서 '최단 경로의 수 찾기 문제'