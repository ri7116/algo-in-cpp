#include<bits/stdc++.h>
using namespace std;
int k;
int n;


int main(){
  cin>>k;
  while(k--){
    int arr[2][100004]={0};
    int d[2][100004]={0};
    cin>>n;
    for(int i=0;i<2;i++){
      for(int j=1;j<=n;j++){
        cin>>arr[i][j];
      }
    }
    d[0][1]=arr[0][1];
    d[1][1]=arr[1][1];
    
    for(int i=2;i<=n;i++){
      d[0][i]=max(d[1][i-1],d[1][i-2])+arr[0][i];
      d[1][i]=max(d[0][i-1],d[0][i-2])+arr[1][i];
    }

    cout<<max({d[0][n],d[0][n-1],d[1][n],d[1][n-1]})<<endl;
  }
}
//1. 한칸옆의 대각선 2. 두칸옆의 대각선
//2. arr[2][100004]={0}; 모든 원소를 0으로 초기화