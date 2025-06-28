#include <bits/stdc++.h>
using namespace std;
int n;
int ls[1004];
int js[1004];
int dp[101];
int ans=-987654321;
int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ls[i];
    }

    for(int i=0;i<n;i++){
        cin>>js[i];
    }

    // for(int i=100;i>=2;i--){
    //     for(int j=0;j<n;j++){
    //         if(i-ls[j]<=0) continue;
    //         if(i+ls[j]>=100) continue;
    //         dp[i-ls[j]]=max(dp[i]+js[j], dp[i-ls[j]]);
    //         ans=max(ans,dp[i-ls[j]]);
    //     }
    // }
    for(int j=0;j<n;j++){
        for(int i=100;i>=ls[j];i--){
            dp[i]=max(dp[i-ls[j]]+js[j], dp[i]);
            ans=max(ans,dp[i-ls[j]]);
        }
    }
    // for(int i=0;i<=100;i++){
    //     cout<<dp[i]<<"\n";
    // }
    // cout<<endl;
    cout<<dp[99];
    
}
//좌항이 우항보다 커야됨