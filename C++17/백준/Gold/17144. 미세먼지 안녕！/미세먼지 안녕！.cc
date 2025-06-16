
#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int Map[1004][1004];
int h_y,h_x;
int l_y,l_x;
int chk=0;
queue<tuple<int,int,int>> q;



int main(){
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Map[i][j];
            if(Map[i][j]==-1){
                if(chk==1){
                    l_y=i;
                    l_x=j;
                }
                else{
                    chk=1;
                    h_y=i;
                    h_x=j;
                }
            }
        }
    }
    while(t--){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Map[i][j]>0){
                    q.push({i,j,Map[i][j]});
                }
            }
        }
        while(!q.empty()){
            int y=get<0>(q.front());
            int x=get<1>(q.front());
            int z=get<2>(q.front());
            q.pop();
            int cnt=0;
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(Map[ny][nx]==-1) continue;
                if(ny<0 or ny>=n or nx<0 or nx>=m ) continue;
                cnt++;
                Map[ny][nx]+=z/5;
            }
            Map[y][x]=Map[y][x]-cnt*(z/5);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<Map[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // 상부 공기청정기 (반시계 방향)    
        for (int i = h_y - 1; i > 0; --i) {
            Map[i][h_x] = Map[i-1][h_x];
        }
        for (int j = 0; j < m - 1; ++j) {
            Map[0][j] = Map[0][j+1];
        }
        for (int i = 0; i < h_y; ++i) {
            Map[i][m-1] = Map[i+1][m-1];
        }
        for (int j = m - 1; j > h_x + 1; --j) {
            Map[h_y][j] = Map[h_y][j-1];
        }
        Map[h_y][h_x+1] = 0;

        // 하부 공기청정기 (시계 방향)
        for (int i = l_y + 1; i < n - 1; ++i) {
            Map[i][l_x] = Map[i+1][l_x];
        }
        for (int j = 0; j < m - 1; ++j) {
            Map[n-1][j] = Map[n-1][j+1];
        }
        for (int i = n - 1; i > l_y; --i) {
            Map[i][m-1] = Map[i-1][m-1];
        }
        for (int j = m - 1; j > l_x + 1; --j) {
            Map[l_y][j] = Map[l_y][j-1];
        }
        Map[l_y][l_x+1] = 0;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<Map[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]>0){
                ans+=Map[i][j];
            }
        }
    }
    cout<<ans;
}
//1. 확산을 큐에 다 넣어놓고 z로 생각하기
//2. 시계방향 이동은 just 반복문 하지만 끝에서 부터 옮겨야지 값의 복사가 잘 일어남을 주의하자