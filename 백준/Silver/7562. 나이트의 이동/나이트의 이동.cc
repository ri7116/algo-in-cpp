#include<bits/stdc++.h>
#define X first   
#define Y second   
using namespace std;
int n;
int cnt;
int visited[604][604];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int k;
  int a,b;
  int c,d;
  cin>>k;
  while(k--){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      visited[i][j]=0;
    }
  }
  cin>>a>>b;
  cin>>c>>d;
  queue<pair<int,int>> q;
  q.push({a,b});
  visited[a][b]=1;
  while(!q.empty()){
    auto cur=q.front();
    q.pop();
    for(int i=0;i<8;i++){
      int nx=cur.X+dx[i];
      int ny=cur.Y+dy[i];
      if(nx>=0 and nx<n and ny>=0 and ny<n and !visited[nx][ny]){
        q.push({nx,ny});
        visited[nx][ny]=visited[cur.X][cur.Y]+1;
      } 
    }
  }
  cout<<visited[c][d]-1<<'\n';
  }
}