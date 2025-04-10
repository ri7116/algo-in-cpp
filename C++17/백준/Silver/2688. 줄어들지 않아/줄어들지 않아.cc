#include<bits/stdc++.h>
using namespace std;

int n,k;
long long arr[1000][10];

int main(){
    cin>>k;

    for(int i=0;i<10;i++){
        arr[1][i]=1;
    }
    for(int i=2;i<=64;i++){
        for(int j=0;j<=9;j++){
            for(int q=9;q>=0+j;q--){
                arr[i][q]+=arr[i-1][j];
            }
        }
    }
    long long ans;
    while(k--){
        cin>>n;
        ans=0;
        for(int i=0;i<10;i++){
            ans+=arr[n][i];
        }
        cout<<ans<<endl;
    }
}