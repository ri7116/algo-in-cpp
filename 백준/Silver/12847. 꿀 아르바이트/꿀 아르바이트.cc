#include<bits/stdc++.h>
using namespace std;

long long k,n;
long long arr[10000004];
long long prx[10000004];
long long prx1[1000004];
long long ans=0;
int main(){
  cin>>k>>n;
  for(long long i=1;i<=k;i++){
    cin>>arr[i];
    prx[i]=arr[i]+prx[i-1];
  }
  for(long long i=n;i<=k;i++){
    prx1[i]=prx[i]-prx[i-n];
    ans=max(ans,prx1[i]);
  }
  cout<<ans;
}