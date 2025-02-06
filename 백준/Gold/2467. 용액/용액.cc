#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005];

int ans1 = 1e9+5;
int ans2 = 1e9+5;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> a[i];
  int st = 0;
  int en = N-1;
  while(st < en){
    if(abs(ans1+ans2) > abs(a[st]+a[en])){
      ans1 = a[st];
      ans2 = a[en];
    }
    if(abs(a[st] + a[en-1]) <= abs(a[st+1] + a[en])) en = en - 1;
    else st = st + 1;
  }
  cout << ans1 << " " << ans2;
}
//어려워서 답지 보고 공부함