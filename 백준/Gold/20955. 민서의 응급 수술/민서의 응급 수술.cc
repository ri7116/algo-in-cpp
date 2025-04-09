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
//1. 트리문제 
//2. 삭제하거나 잇는 연산
//3. 잇는 연산은 연결된 컴포넌트 갯수 -1
//4. 삭제 연산은 m+추가된 연결선-(삭제연산)=노드수-1