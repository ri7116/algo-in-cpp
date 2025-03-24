#include<bits/stdc++.h>
using namespace std;

int n;
int d[10][1004];

int main(){
  cin>>n;

  for(int i=0;i<=9;i++) d[i][1]=1;
  
    
  for(int i=1;i<=n;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=j;k++){
        d[j][i+1] = (d[j][i+1] + d[k][i]) % 10007;
      }
    }
  }
  int ans=0;
  for(int i=0;i<=9;i++) ans = (ans + d[i][n]) % 10007;
  cout<<ans;
}
//1. 모듈러 연산 +=는 모듈러 연산 적용하기 쉽지 않음