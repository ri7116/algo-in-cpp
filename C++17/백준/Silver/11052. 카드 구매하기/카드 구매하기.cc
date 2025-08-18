#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100004];
int dp[100004];
int fuc(int k){
    if(k==0) return 0;

    if(dp[k]) return dp[k];
    int tmp=0;
    for(int i=0;i<n;i++){
        if(k-i>=1) tmp=max(tmp, arr[i]+fuc(k-(i+1)));
    }
    return dp[k]=tmp;
}



int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<fuc(n);
}