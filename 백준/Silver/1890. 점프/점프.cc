// 브루트 포스 비효율적인 문제
// #include<bits/stdc++.h>
// using namespace std;
// int arr[1000][1000];
// int dp[1000][1000];
// int n;
// int dx[2] = {0, +1};
// int dy[2] = {+1, 0};
// void dfs(int y,int x){
//     if(arr[y][x] == 0) {
//         dp[y][x]++;
//         return;
//     }


//     for(int i=0;i<2;i++){
//         int ny=y+dy[i]*arr[y][x];
//         int nx=x+dx[i]*arr[y][x];
//         if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
//         dfs(ny,nx);
//     }
// }
// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     dfs(0,0);
//     cout<<dp[n-1][n-1];
// }




#include<bits/stdc++.h>
using namespace std;
long long arr[1000][1000];
long long dp[1000][1000];
long long n;
long long dx[2] = {0, +1};
long long dy[2] = {+1, 0};
long long dfs(long long y,long long x){
    if(y<0 || y>=n || x<0 || x>=n) return 0;
    if(y==n-1 && x== n-1)  return 1;
    if(dp[y][x] != -1) return dp[y][x];
    if(arr[y][x] == 0) return 0;
    return dp[y][x] = dfs(y+dy[0]*arr[y][x], x+dx[0]*arr[y][x]) + dfs(y+dy[1]*arr[y][x], x+dx[1]*arr[y][x]);
}
int main(){
    cin>>n;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j] = -1; 
        }
    }
    cout<<dfs(0,0);
}