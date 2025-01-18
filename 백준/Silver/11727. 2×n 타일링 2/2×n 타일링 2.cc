#include<bits/stdc++.h>
using namespace std;
int n;
int ans[1004];
int main(){
  cin>>n;
  ans[1]=1;
  ans[2]=3;
  for(int i=3;i<=n;i++){
    ans[i]=(ans[i-1]+2*ans[i-2])%10007;
  }

  cout<<ans[n];
}