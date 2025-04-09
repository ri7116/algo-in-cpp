#include<bits/stdc++.h>
using namespace std;
int n,m;
int visited[10000000];
vector <int> v[10000000];
int ans;
void dfs(int cur){
  visited[cur]=1;

  for(auto a:v[cur]){
    if(visited[a]) continue;
    dfs(a);
  }

}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      dfs(i);
      ans++;
    }
  }
  cout<<m+2*(ans-1)-(n-1);
}