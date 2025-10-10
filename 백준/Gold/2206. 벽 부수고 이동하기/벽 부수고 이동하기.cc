#include<bits/stdc++.h>
using namespace std;

int n,m;
int Map[1004][1004];
string str;

int dy[4]= {1,0,-1,0};
int dx[4]= {0,1,0,-1};
int visited[1004][1004][2];

struct st{
    int a;
    int b;
    int c;
};


queue<st> q;

void bfs(int a, int b){
    q.push({a,b,0});
    visited[a][b][0]=1;

    while(!q.empty()){
        int y=q.front().a;
        int x=q.front().b;
        int cnt=q.front().c;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 or ny>=n or nx<0 or nx>=m) continue;
            if(Map[ny][nx]==0 and visited[ny][nx][cnt] == 0){//벽이 아니고 부수지 않고 방문한적 없을 때
                q.push({ny,nx,cnt});
                visited[ny][nx][cnt]=visited[y][x][cnt]+1;
            }
            if(Map[ny][nx]==1 and cnt==0 and visited[ny][nx][1] == 0){//
                q.push({ny,nx,1});
                visited[ny][nx][1]=visited[y][x][0]+1;
            }
        }
    }
}



int main(){
    // 0,0부터 n-1, m-1 도착 해야함.
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            Map[i][j]=str[j]-'0';
        }
    }
    bfs(0,0);


    // 두 상태 다 방문하지 못한 경우
    if (visited[n-1][m-1][0] == 0 && visited[n-1][m-1][1] == 0) {
        cout << -1;
    }
    // 벽을 안 부순 경우만 도달 가능
    else if (visited[n-1][m-1][0] != 0 && visited[n-1][m-1][1] == 0) {
        cout << visited[n-1][m-1][0];
    }
    // 벽을 부순 경우만 도달 가능
    else if (visited[n-1][m-1][0] == 0 && visited[n-1][m-1][1] != 0) {
        cout << visited[n-1][m-1][1];
    }
    // 둘 다 도달 가능 → 최소 거리 출력
    else {
        cout << min(visited[n-1][m-1][0], visited[n-1][m-1][1]);
    }
}