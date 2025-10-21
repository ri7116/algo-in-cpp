#include<bits/stdc++.h>
#include<vector>
using namespace std;
int visited[104][104];
queue<pair<int,int>> q;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
void bfs(int a,int b,int n, int m,vector<vector<int>>& maps){
    q.push({a, b});
    visited[a][b]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny < 0 or nx < 0 or ny>=n or nx>=m) continue;
            if(visited[ny][nx]!=-1) continue;
            if(maps[ny][nx]==0) continue;
            q.push({ny,nx});
            visited[ny][nx]=visited[y][x]+1;
        }
    }
}

int solution(vector<vector<int> > maps)
{
    //visited 처음 초기화???
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            visited[i][j]=-1;
        }
    }
    
    bfs(0,0,maps.size(),maps[0].size(),maps);
    int answer = visited[maps.size()-1][maps[0].size()-1];
    
    return answer;
}

