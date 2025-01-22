#include<bits/stdc++.h>
using namespace std;
int vertex_num, edge_num, ans;
tuple<int,int,int> edge[100005];//크기, 시작점, 끝점점
vector<int> p(10005,-1);
//부모 찾기
int find(int x){
  if(p[x]<0) return x;//
  else return p[x]=find(p[x]);
}

//합치는 연산 
bool uni(int u, int v){
  int uroot=find(u);
  int vroot=find(v);
  if(uroot==vroot) return false;
  p[vroot]=uroot;
  return true;
}

int main(){
  cin>>vertex_num>>edge_num;
  for(int i=0;i<edge_num;i++){
    int cost,a,b;
    cin>>a>>b>>cost;
    edge[i]={cost,a,b};
  }
  int cnt=0;
  sort(edge,edge+edge_num);
    for(int i=0;i<edge_num;i++){
    int cost,a,b;
    tie(cost,a,b)=edge[i];
    if(!uni(a,b)) continue;
    ans+=cost;
    cnt++;
    if(cnt==vertex_num-1) break;
  }
  cout<<ans;
}