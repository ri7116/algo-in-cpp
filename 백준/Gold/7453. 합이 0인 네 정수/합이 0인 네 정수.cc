#include<bits/stdc++.h>
using namespace std;

int n;
long long A[4004];
long long B[4004];
long long C[4004];
long long D[4004];
vector<long long> SUM1;
vector<long long> SUM2;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>A[i]>>B[i]>>C[i]>>D[i]; 
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      SUM1.push_back(A[i]+B[j]);
    }
  }  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      SUM2.push_back(C[i]+D[j]);
    }
  }

  sort(SUM2.begin(),SUM2.end());
  long long ans=0;
  for(int i=0;i<SUM1.size();i++){
    ans+=upper_bound(SUM2.begin(),SUM2.end(),-SUM1[i])-lower_bound(SUM2.begin(),SUM2.end(),-SUM1[i]);
  }
  cout<<ans;
}
//1. 이분탐색에서 등장 횟수(바운드)인지 존재(st<ed)인지는 다름 
//2. nC2에서 하나의 배열에서 구하는것이냐 서로다른 두 배열에서 구하는 것이냐도 다름