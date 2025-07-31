#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long dp[504][504];
long long arr[504][504];
long long dy[4]={1,0,-1,0};
long long dx[4]={0,1,0,-1};
long long processed[504][504];
long long dfs(long long y,long long x){
    if(y==n-1 and x==m-1) return 1;// 목적지 도착하는 경우의 수 있으면 +1
    if(y<0 or x<0 or y>=n or x>=m) return 0;//범위 초과면 return 0; (1) 일단 go
    if(processed[y][x]!=0) return dp[y][x];
    processed[y][x]=1;
    //cout<<y<<" "<<x<<endl;

    for(int i=0;i<4;i++){
        long long ny=y+dy[i];
        long long nx=x+dx[i];
        if(arr[y][x]<=arr[ny][nx]) continue;
        //if(ny<0 or nx<0 or ny>=n or nx>=m) continue; (2) 가지도 말자 
        dp[y][x]+=dfs(ny,nx);
    }
    return dp[y][x];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<dfs(0,0);
    
}
//dfs + dp