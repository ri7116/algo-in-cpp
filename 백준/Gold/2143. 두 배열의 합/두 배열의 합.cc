#include<bits/stdc++.h>
using namespace std;
long long arr[1004];
long long arr1[1004];

long long pre[1004];
long long pre1[1004];
vector<long long> v;
vector<long long> v1;
long long ans;
int main(){
  long long k,n,m;
  cin>>k;
  cin>>n;
  //배열 0 누적합
  for(long long i=1;i<=n;i++){
    cin>>arr[i];
  }
  for(long long i=1;i<=n;i++){
    pre[i]=arr[i]+pre[i-1];
  }
  for(long long i=1;i<=n;i++){
    for(long long j=i;j<=n;j++){
      v.push_back(pre[j]-pre[j-i]);
    }
  }
  cin>>m;
  //배열 1 누적합
  for(long long i=1;i<=m;i++){
    cin>>arr1[i];
  }
  for(long long i=1;i<=m;i++){
    pre1[i]=arr1[i]+pre1[i-1];
  }
  for(long long i=1;i<=m;i++){
    for(long long j=i;j<=m;j++){
      v1.push_back(pre1[j]-pre1[j-i]);
    }
  }
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  for(long long i=0;i<v.size();i++){
    ans+=upper_bound(v1.begin(),v1.end(),k-v[i])-lower_bound(v1.begin(),v1.end(),k-v[i]) ;
  }
  cout<<ans;
}

//1. 누적합
//2. 이분탐색 바이너리 서치는 존재여부 upperbound()-lower_bound()=나온 갯수
//3. 투포인터