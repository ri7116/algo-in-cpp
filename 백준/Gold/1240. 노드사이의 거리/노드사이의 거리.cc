#include<bits/stdc++.h>
using namespace std;
bool visited[1004];
int m,n;
int d;
vector<pair<int,int>> node[1004];

void dfs(int cur, int target){
  visited[cur]=1;
  for(auto next:node[cur]){
    if(visited[next.first]==1) continue;
    d+=next.second;
    if(target==next.first) cout<<d<<'\n';//목표 방문시 다 끝내버려
    dfs(next.first, target);
    d-=next.second;//원복
  }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    node[a].push_back({b,c});
    node[b].push_back({a,c});
  }
    for(int i=0;i<m;i++){
      int a,b;
      //!!이 부분 조심해보자
      //!! 여기까지
      cin>>a>>b;
      dfs(a,b);
      for(int j=0;j<1004;j++){
        visited[j]=0;
      }
      d=0; //원복
    }
}