#include<bits/stdc++.h>
using namespace std;
int node;
int vertex;
int k;
vector<int> v[1000004];
int visited[1000004];
int cnt;

void DFS(int n){
  visited[n]=1;
  cnt++;

  for(auto a: v[n]){
    if(visited[a]) continue;
    DFS(a);
  }
}


int main(){
  cin>>k;
  

  while(k--){
    cnt=0;
    for(int i=0;i<1000004;i++){
      v[i].clear();
      visited[i]=0;
    }
    cin>>node;
    cin>>vertex;
    
    int a,b;
    for(int i=0;i<vertex;i++){
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }

    
    //간선의 수 != 노드 수 
    if(node-1!=vertex) {
      cout<<"graph\n";
      continue;
    }

    DFS(a);
    //딱 node 수 만큼만 방문 => tree 
    if(cnt==node) cout<<"tree\n";
    else cout<<"graph\n";
  }
}

//1. vertex== node-1
//2. DFS시 모든 노드를 한번 방문
//3. while(k)인 경우에 항상 초기세팅으로 되돌려야함