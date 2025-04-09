#include<bits/stdc++.h>
using namespace std;
int n;
int ans=9876543210;
int arr[14];
vector<pair<int,int>> v;
void fuc(int depth){
    if(depth==n){
      int tmp=1;
      int tmp2=0;
      int check=0;
      for(int i=0;i<n;i++){
        if(arr[i]==0) continue;
        check=1;
        tmp*=v[i].first;
        tmp2+=v[i].second;
      }
      if(check==0) return;
      ans=min(ans,abs(tmp-tmp2));
      return;
    }
    for(int i=0;i<2;i++){
      arr[depth]=i;
      fuc(depth+1);
    }
}



int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
  }
  fuc(0);
  cout<<ans;
}
//순열 완전탐색색