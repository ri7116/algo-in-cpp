#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10004];
int dp[10004];
int ans;
int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        ans=max(dp[i],ans);
    }

    cout<<ans<<endl;
    return 0;
}
//i 정해두고 1부터 i-1까지 전부 선택하기 