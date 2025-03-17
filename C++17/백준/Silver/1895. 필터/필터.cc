#include<bits/stdc++.h>
using namespace std;
int m,n,t;
int arr[1000][1000];
int ans;
int num[10];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>t;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            num[0]=arr[i][j];
            num[1]=arr[i+1][j];
            num[2]=arr[i+2][j];
            num[3]=arr[i][j+1];
            num[4]=arr[i][j+2];
            num[5]=arr[i+1][j+1];
            num[6]=arr[i+2][j+2];
            num[7]=arr[i+1][j+2];
            num[8]=arr[i+2][j+1];
            sort(num,num+9);
            if(t<=num[4]) ans++;
        }
    }
    cout<<ans;
}