#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1004][1004];
int d[1004][1004];
int ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=1;j<=m;j++){
            arr[i][j]=str[j-1]-'0';//-48
            
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]!=0 and arr[i-1][j-1]!=0 and arr[i-1][j]!=0 and arr[i][j-1]!=0) d[i][j]=min(d[i-1][j-1],min(d[i][j-1],d[i-1][j]))+1;
            else d[i][j]=arr[i][j];
            if(d[i][j]>ans) ans=d[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<pow(ans,2);
}