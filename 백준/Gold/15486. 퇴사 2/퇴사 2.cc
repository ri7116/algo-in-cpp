#include<bits/stdc++.h>
using namespace std;
int n;
int node[2000000][2];
int ans[2000000];
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    int a,b;
    cin>>a>>b;
    node[i][0]=a;
    node[i][1]=b;
  }
  for(int i=n;i>=1;i--){
    if(node[i][0]<=n-i+1){//현재 타임의 상담을 잡을 수 있다면?
      ans[i]=max(ans[i+1], ans[i+node[i][0]]+node[i][1]);//상담 안잡, 상담 잡
    }
    else{//현재 타임의 상담을 잡을 수 없다면?
      ans[i]=ans[i+1];
    }
  }
  cout<<ans[1];
}
//반대로 뒤부터 생각하는게 쉽지 않네? 처음 봤으면 풀 수 있었을까?