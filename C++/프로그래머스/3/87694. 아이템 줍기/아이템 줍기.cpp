#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int arr[1004][1004];
queue<pair<int,int>> q;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int visited[1000][1000];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for (int i = 0; i < rectangle.size(); i++){
        for (int j = 0; j < rectangle[0].size(); j++){
            rectangle[i][j] = rectangle[i][j] * 2;
        }
    }
    
    for(int k=0;k<rectangle.size();k++){
        
        for(int i=rectangle[k][1];i<=rectangle[k][3];i++){
            for(int j=rectangle[k][0];j<=rectangle[k][2];j++){
                if( arr[i][j] == 1 ) continue;
                
                if( i == rectangle[k][1] or i == rectangle[k][3] or j == rectangle[k][0] or j == rectangle[k][2]) arr[i][j]=2;
                else arr[i][j]=1;
            }
        }
        
    }
    //최단거리 찾기
    q.push({2*characterY,2*characterX});
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 or ny>100 or nx<0 or nx>100) continue;// 범위 밖이면 가지마
            if(arr[ny][nx] != 2) continue;//갈수 잇는 길이 아니면 가지마
            if(visited[ny][nx]) continue;//이미 방문 했으면 가지마
            visited[ny][nx]=visited[y][x]+1;
            q.push({ny,nx});
            cout<<ny<<" : "<<nx<<"방문이요\n";
        }
    }    

    answer=visited[2*itemY][2*itemX];
    return answer/2;
}