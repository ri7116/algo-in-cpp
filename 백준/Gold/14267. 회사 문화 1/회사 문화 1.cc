#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[100004];
int ans[100004];
int visited[100004];
vector<int> v[100004];

void dfs(int cur,int parent){
  visited[cur]=1;
  ans[cur]+=ans[parent];

  for(auto a:v[cur]){
    if(visited[a]) continue;
    dfs(a,cur);
  }
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    v[a].push_back(i);
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    ans[a]+=b;
  }
  dfs(1,1);
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
}

// https://barbera.tistory.com/28 여기 설명이 아주 야무짐 