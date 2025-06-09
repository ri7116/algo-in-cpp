#include<bits/stdc++.h>
using namespace std;

string str;
char Map[12][6];
int visited[12][6];
vector<pair<int,int>> v;
int cnt;
int is_pop;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans;

void dfs(char cur,int y,int x){
    visited[y][x]=1;
    cnt++;
    v.push_back({y,x});
    //cout<<y<<" : "<<x<<" 방문이요\n";

    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 or nx<0 or ny>=12 or nx>=6) continue;
        if(visited[ny][nx] or Map[ny][nx]!=cur) continue;
        dfs(cur,ny,nx);
    }
}

int main(){
    for(int i=0;i<12;i++){
        cin>>str;
        for(int j=0;j<6;j++){
            Map[i][j]=str[j];
        }
    }    
    while(1){
        is_pop=0;

        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                visited[i][j]=0;
            }
        }
        
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                cnt=0;
                v.clear();
                
                if(!visited[i][j] and Map[i][j]!='.') dfs(Map[i][j],i,j);
                if(cnt>=4){
                    is_pop=1;
                    for(auto a:v){
                        Map[a.first][a.second]='.';
                    }
                }
            }
        }
        // 뿌요들 내려오게 만들기!! (아래에서 위로 흝고 채워넣기) 
        queue<char> q;
        for(int i=0;i<6;i++){
            for(int j=11;j>=0;j--){
                if(Map[j][i]!='.') q.push(Map[j][i]);
            }
            for(int j=11;j>=0;j--){
                if(q.empty()){
                    Map[j][i]='.';
                    continue;
                }
                Map[j][i]=q.front();
                q.pop();
            }
        }

        if(!is_pop) break;
        ans++;

        //cout<<"=====================\n";
    }
    cout<<ans;
}