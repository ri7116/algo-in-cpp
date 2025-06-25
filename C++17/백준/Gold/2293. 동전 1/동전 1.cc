#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int dp[100004]; 
int a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        dp[a]+=1;
        for(int j=a;j<=k;j++){
            dp[j]=dp[j]+dp[j-a];
        }
    }
    cout<<dp[k];
}
//중복이 가능하기 때문에 정방향으로 돌린다.