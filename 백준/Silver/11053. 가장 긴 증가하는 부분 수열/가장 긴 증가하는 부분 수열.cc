#include <bits/stdc++.h>
using namespace std;

int n;
int a[1004]; //수열 넣기
int d[1004]; //가장 긴 증가하는 부분 수열

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    d[i]=1;
  }

  for(int i = 1; i <= n; i++){
    for(int j=1;j<  i;j++){
        if(a[j]<a[i]){
            d[i]=max(d[i],d[j]+1);//현재 길이 or 이전 수열의 길이 +1
        }
    }
  }
  cout << *max_element(d+1 , d + n + 1);  //1부터 시작하니까~
}