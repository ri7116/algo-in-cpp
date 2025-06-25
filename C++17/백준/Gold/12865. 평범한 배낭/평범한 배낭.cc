#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[1000004];
int w,v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    while(n--){
        cin>>w>>v;
        for(int i=k;i>=w;i--){
            dp[i]=max(dp[i],dp[i-w]+v);
        }
    }
    cout<<dp[k];
}
//역순으로 하지 않으면 현재 고려 중인 물건을 포함하여 갱신된 값일 수 있다.