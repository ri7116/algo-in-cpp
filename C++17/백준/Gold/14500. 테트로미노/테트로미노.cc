    #include<bits/stdc++.h>
using namespace std;
int ans=-1;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int visited[1050][1050];
int Map[1050][1050];
deque< pair<int,int> > q;
void dfs(int depth,int y,int x){
    if(depth==4){
        int tmp=0;
        for(auto a: q){
            tmp+=Map[a.first][a.second];
        }
        ans=max(ans,tmp);
        return;
    }

    for(int i=0;i<4;i++){
        int ny=dy[i]+y;
        int nx=dx[i]+x;
        if(visited[ny][nx]) continue;
        visited[ny][nx]=1;
        q.push_back({ny,nx});
        dfs(depth+1,ny,nx);
        visited[ny][nx]=0;
        q.pop_back();
    }
}
void check_t(int y, int x) {
    // 각 방향에서 3개의 이웃을 골라 합산
    // 0: 위쪽 제외, 1: 오른쪽 제외, 2: 아래쪽 제외, 3: 왼쪽 제외
    int center = Map[y][x];
    for (int i = 0; i < 4; i++) {
        int tmp = center;
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            int ny = y + dy[j], nx = x + dx[j];
            tmp += Map[ny][nx];
        }
        ans = max(ans, tmp);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=10;i<n+10;i++){
        for(int j=10;j<m+10;j++){
            cin>>Map[i][j];
        }
    }
    for(int i=10;i<n+10;i++){
        for(int j=10;j<m+10;j++){
            visited[i][j] = true;
            q.push_back({i,j});       
            dfs(1,i,j);
            q.pop_back();
            visited[i][j] = false;
            check_t(i, j);
        }
    }
    cout<<ans;    
}
//1. dfs 4로하기 모양 한개는 직접 비교하기
//2. segment 오류를 벗어나기 위해서 그냥 i j 를 중간에 넣는걸로 해버림 왜냐? 최대값이기 때문에 문제가 생기지 않음