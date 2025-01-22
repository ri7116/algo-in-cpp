#include<bits/stdc++.h>
using namespace std;
int k, n;
int node[1004][1004];
int p[1004];
int ans[1004];
//부모 찾기
int find(int x){
  if(p[x]<=0) return x;//
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
  cin>>n;
  cin>>k;
  int tmp;
  for(int i=1;i<=n;i++){//(i가 더 작으면 스왑 해야하나?)
    for(int j=1;j<=n;j++){
      cin>>tmp;
      if(tmp) {
        uni(i,j);
      }
    }
  }
  for(int i=1;i<=k;i++){
    cin>>ans[i];
  }

  for(int i=2;i<=k;i++){
    if(find(ans[i])!=find(ans[i-1])){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
}