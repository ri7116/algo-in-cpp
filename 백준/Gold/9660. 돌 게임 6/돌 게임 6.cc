#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  // 1 상근
  // 2 창영                 2
  // 3 상근
  // 4 상근
  // 4 2 1 상근
  // 5 3 2 상근
  // 6 4 3 창영            7
  // 7 5 4 상근
  // 8 6 5 창영             9
  // 9 7 6 상근
  // 10 8 7 상근
  // 11 9 8 상근
  // 12 10 9 상근
  // 창영                        14
  // 상근
  // 창영                         16
  // 상근
  // 상근
  // 상근
  // 상근
  // 창영 21
  // 상근
  // 창영영 23
  long long a;
  cin>>a;
  if(a%7==0 or (a%7==2)) cout<<"CY";
  else cout<<"SK";
}