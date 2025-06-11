#include<bits/stdc++.h>
using namespace std;

int ans=2100000000;

int visited[5][5][5];
int dx[6] = {0,0,-1,0,0,1};
int dy[6] = {-1,0,0,1,0,0};
int dz[6] = {0,1,0,0,-1,0};
int arr[5][5][5];
int decision[5][5][5];
int last[5][5][5];

int H_arr[5];
int P_arr[5];
int P_visited[5];

//dfs 함수 
// void dfs(int depth, int z,int y, int x){
//     if(z==4 and y==4 and x==4)    {
//         //out<<"목적지에 도착 했습니다\n";
//         ans=min(depth,ans);
//         return;
//     }
//     visited[z][y][x]=1;
//     //종점지 처리
    
    

//     for(int i=0;i<6;i++){
//         int nz=z+dz[i];
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         if(nz<0 or ny<0 or nx<0 or nz>=5 or ny>=5 or nx>=5) continue;
//         if(visited[nz][ny][nx]==1) continue;
//         if(last[nz][ny][nx]==0) continue;
//         dfs(depth+1,nz,ny,nx);
//     }
//     visited[z][y][x]=0;
// }



//배열 회전 함수
void Trun(int idx,int num){
    if(num==0){//그대로
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                decision[idx][i][j]=arr[idx][i][j];
            }
        }
    }
    if(num==1){//시계방향 90도
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                decision[idx][i][j]=arr[idx][5-1-j][i];
            }
        }
    }
    if(num==2){//시계방향 180도
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                decision[idx][i][j]=arr[idx][5-1-i][5-1-j];
            }
        }
    }
    if(num==3){//시계방향 270도
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                decision[idx][i][j]=arr[idx][j][5-1-i];
            }
        }
    }
}

//배열 위치 순열 함수 
void P(int depth){
    if(depth==5){
        for(int k=0;k<5;k++){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    last[k][i][j]=decision[P_arr[k]][i][j];
                }
            }
        }
        //여기서 dfs실행해야됨 xx dfs는 시간 복잡도의 문제로 bfs를 실행해야됨
        if(last[0][0][0]==0) return;



        queue<tuple<int,int,int>> q;
        visited[0][0][0]=1;
        q.push({0,0,0});

        while(!q.empty()){
            int z=get<0>(q.front());
            int y=get<1>(q.front());
            int x=get<2>(q.front());
            q.pop();

            for(int i=0;i<6;i++){
                int nz=z+dz[i];
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(nz<0 or ny<0 or nx<0 or nz>=5 or ny>=5 or nx>=5) continue;
                if(visited[nz][ny][nx]!=0) continue;
                if(last[nz][ny][nx]==0) continue;
                visited[nz][ny][nx]=visited[z][y][x]+1;
                q.push({nz,ny,nx});
            }
        }

        if(visited[4][4][4]!=0)    {
            //out<<"목적지에 도착 했습니다\n";
            ans=min(ans,visited[4][4][4]-1);
        }

        //visited 초기화
        for(int k=0;k<5;k++){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    visited[k][i][j]=0;
                }
            }
        }
        return;
    }

    for(int i=0;i<=4;i++){
        if(P_visited[i]) continue;
        P_arr[depth]=i;
        P_visited[i]=1;
        P(depth+1);
        P_visited[i]=0;
    }
}


//배열 회전 선택 중복 순열
void H(int depth){
    if(depth==5){
        Trun(0,H_arr[0]);
        Trun(1,H_arr[1]);
        Trun(2,H_arr[2]);
        Trun(3,H_arr[3]);
        Trun(4,H_arr[4]);
        P(0);
        return;
    }

    for(int i=0;i<=3;i++){
        H_arr[depth]=i;
        H(depth+1);
    }
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin>>arr[k][i][j];
            }
        }
    }
    H(0);
    
    if(ans==2100000000) cout<<-1;
    else cout<<ans;
}
// 1. 순열과 조합
// 2. bfs







