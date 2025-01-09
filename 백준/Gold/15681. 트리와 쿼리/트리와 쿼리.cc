#include<bits/stdc++.h>
using namespace std;

int n,r,q;
vector <int>node[100004];
vector <int>chid[100004];
int visited[100004];
const int MXN = 10e5 + 10;
int  subTreeSize[MXN];

int dfs(int cur){
  visited[cur]=1;
  for(auto next : node[cur]){
    if(visited[next]) continue;
    subTreeSize[cur] += dfs(next);
  }
  subTreeSize[cur]++;
  return subTreeSize[cur];
}

int count(int cur, int& cnt){
  for(auto a:chid[cur]){
    cnt++;
    //cout<<"cnt: "<<cnt<<endl;
    count(a,cnt);
  }
  return cnt;
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>r>>q;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(r);
  // for(int i=1;i<=n;i++){
  //   cout<<i<<" :";
  //   for(auto a: chid[i]){
  //     cout<<a<<" ";
  //   }
  //   cout<<"\n";
  // }
  
  while (q--) {
    int a;
    cin >> a;
    cout << subTreeSize[a] << '\n';
  }
}