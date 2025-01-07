#include<bits/stdc++.h>
using namespace std;
int n;
int a,b;

vector <int> node[100004];
int parent[100004];

void dfs(int cur){
  for(auto next: node[cur]){
    if(parent[cur]==next) continue;
    parent[next]=cur;
    dfs(next);
    //cout<<"재귀여";
  }
}
int  main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(1);
  for(int i=2;i<=n;i++){
    cout<<parent[i]<<'\n';
  }
}