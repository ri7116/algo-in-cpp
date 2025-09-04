#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int n,m;
int arr[1000][1000];
int ans= INF;
int ans_num= INF;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=1000000000;
            if(i==j) arr[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k]+arr[k][j]<arr[i][j]) {
                    arr[i][j] = arr[i][k]+arr[k][j];                    
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=arr[i][j];
        }
        if(ans_num>tmp){
            ans_num=tmp;
            ans=i;
        }
        else if(ans_num==tmp){
            ans=min(ans,i);
        }
    }
    cout<<ans;
}