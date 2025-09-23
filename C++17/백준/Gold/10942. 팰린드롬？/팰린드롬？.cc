
#include<bits/stdc++.h>
using namespace std;
int dp[2004][2004];
int n,k;
int arr[2004];



int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i][i]=1; //길이 1
    }
    //길이 2
    for(int i=0;i<n-1;i++){
        if(arr[i+1]==arr[i]) dp[i][i+1]=1;
    }
    //길이가 3이상
    for(int i=3;i<=n;i++){
        for(int j=0;j+i-1 < n;j++){
            if(arr[j]==arr[j+i-1] and dp[j+1][j+i-2]==1) dp[j][j+i-1]=1; 
        }
    }
    //cout<<"이거 실행됨?";
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        cout<<dp[a-1][b-1]<<'\n';
    }
}