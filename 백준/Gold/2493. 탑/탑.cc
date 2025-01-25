// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/44465623025e452bba5feb80b0b0e60e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int,int>> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  tower.push({100000001, 0});
  for (int i = 1; i <= N; i++) {    
    int hight; 
    cin>>hight;
    while(tower.top().X<hight){
      tower.pop();
    }
    cout<<tower.top().Y<<" ";
    tower.push({hight,i});
  }
}
//내 코드는 시간초과 떠서 답지보고 공부함