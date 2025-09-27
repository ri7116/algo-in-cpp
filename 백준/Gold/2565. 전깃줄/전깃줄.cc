#include<bits/stdc++.h>
using namespace std;
int a,b;
int k;
int arr[504];
int dp[504];
int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        arr[a]=b;
    }
    for(int i=0;i<500;i++){
        int tmp=0;
        if(arr[i]==0) continue;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]) tmp=max(tmp,dp[j]+1);
        }
        dp[i]=tmp;
    }
    cout<<k-*max_element(dp,dp+500)<<endl;
    // cout<<"=====================\n";
    // for(int i=0;i<100;i++){
    //     cout<<dp[i]<<endl;
    // }
}
//시간 복잡도 n^2 50 * 50 = 2500;