#include<bits/stdc++.h>
using namespace std;
int n,m;
int cur_x,cur_y,direction;
int Map[1000][1000];
int visited[1000][1000];
int ans;

int Check(int y,int x){
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    if(y+1>=0 and y+1<n and x>=0 and m>x and Map[y+1][x]!=1 and !visited[y+1][x]) a=1;
    if(y>=0 and y<n and x+1>=0 and m>x+1 and Map[y][x+1]!=1 and !visited[y][x+1]) b=1;
    if(y-1>=0 and y-1<n and x>=0 and m>x and Map[y-1][x]!=1 and !visited[y-1][x]) c=1;
    if(y>=0 and y<n and x-1>=0 and m>x-1 and Map[y][x-1]!=1 and !visited[y][x-1]) d=1;
    
    if(a+b+c+d) return 1;//청소할 곳 있는 경우
    else return 0;
}
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int main(){
    cin>>n>>m;
    cin>>cur_y>>cur_x>>direction;
    if(direction==1) direction=3;
    else if(direction==3) direction=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Map[i][j];
        }
    }
    while(1){
        if(Map[cur_y][cur_x]!=1 and !visited[cur_y][cur_x]) {
            visited[cur_y][cur_x]=1;
            ans++;
        }
        if(Check(cur_y,cur_x)){//청소할 곳 있는 경우
            while(1){
                direction++;
                direction=direction%4;//반시계 반향으로 회전
                int ny=cur_y+dy[direction];
                int nx=cur_x+dx[direction];
                if(ny>=0 and ny<n and nx>=0 and m>nx and Map[ny][nx]!=1 and !visited[ny][nx]) {//앞쪽 칸이 청소되지 않은 빈 칸인 경우 한칸 전진
                    cur_x=nx;
                    cur_y=ny;
                    break;
                }
            }
        }
        else{//청소할 곳이 없는 경우
            int tmp_direction=(direction+2)%4;
            int nx=cur_x+dx[tmp_direction];
            int ny=cur_y+dy[tmp_direction];
            
            //뒤가 벽이면
            if(ny<0 or ny>=n or nx<0 or m<=nx or Map[ny][nx]==1){
                break;
            }
            //뒤가 벽이 아니면
            else{
                //방향 유지한 채로 후진
                cur_y=ny;
                cur_x=nx;
            }
        }
    }
    cout<<ans;
}