#include<bits/stdc++.h>
using namespace std;

int n;
int arr[504][504];
int dp[504][504];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int ans= -1;
int w(int y,int x){
    //방문처리
    if(dp[y][x] != -1) return dp[y][x];
    //정답은 max(depth임)

    dp[y][x]=1;


    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        //범위 벗어나면 continue
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        //대나무 수가 이전보다 이후가 작아도 continue
        if(arr[ny][nx] <= arr[y][x]) continue;
        
        //함수에 넣자
        dp[y][x] = max(dp[y][x], w(ny, nx)+1);
    }
    //상하좌우 방향으로 이동
    //칸 넘어가면 continue
    //방문 했었어도 continue
    //대나무 수가 이전보다 이후가 작아도 continue
    //함수에 넣자
    //return 함수 + 1
    //방문처리 원복
    return dp[y][x];
    
}






int main(){
    cin>> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j] = -1; // dp 배열 초기화
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mx=max(mx,w(i,j));
        }
    }
    cout<<mx<<endl; // 
}

//bottom up 저격문제(채우는 순서가 너무 어려움)
//bfs+dp