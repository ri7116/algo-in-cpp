#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int visited[100][100];
int visited2[100][100];
int chk;

int dy[4] ={1,0,-1,0};
int dx[4] ={0,1,0,-1};

void reset(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visited2[i][j]=0;
        }
    }
}

void dfs(int y,int x,vector<string> storage){
    if(y==0 or x==0 or x==storage[0].size()-1 or y==storage.size()-1) {
        chk=1;
        return;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 or ny>= storage.size() or nx<0 or nx>=storage[0].size()) continue;
        if(visited[ny][nx]==0) continue;//안 뚫려있으면
        if(visited2[ny][nx]==1) continue;//방문 했으면
        visited2[ny][nx]=1;
        dfs(ny,nx,storage);
        //원복 해야하나?
        //안해도 되네
    }
}


int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    for(int k=0;k<requests.size();k++){
        
        if(requests[k].size()==2){
            for(int i=0;i<storage.size();i++){
                for(int j=0;j<storage[0].size();j++){
                    if(visited[i][j]) continue;//이미 빼냈으면 넘어간다.
                    
                    if(storage[i][j]==requests[k][0]){
                        cout<<i<<" : "<<j<<"빼낸다"<<" 길이2\n";
                        visited[i][j]=1;
                        cnt++;       
                    }

                }
            }
        }
        
        else{
            vector<pair<int,int>> v;
            for(int i=0;i<storage.size();i++){
                for(int j=0;j<storage[i].size();j++){
                    if(visited[i][j]) continue;
                    if(storage[i][j]!=requests[k][0]) continue;
                    chk=0;
                    reset();
                    dfs(i,j,storage);
                    if(chk==1) {//dfs로 바깥 갈 수 있으면 추가하자
                        cnt++;
                        cout<<i<<" : "<<j<<"빼낸다\n";
                        v.push_back({i,j});
                    }
                }
            }
            //! 이거 주의하자 시간선!!!!
            for(auto a:v){
                visited[a.first][a.second]=1;
            }
        }
        
    }
    answer=storage.size()*storage[0].size()-cnt;
    return answer;
}