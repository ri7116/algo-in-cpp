#include <bits/stdc++.h>
using namespace std;
int bit=0;
int k;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> k;
  while (k--) {
    string str;
    int a;
    cin >> str;

    if (str == "add") {
      cin >> a;
      bit |=(1<<a);//a만큼 옮겨서 비트를 킨다.
    }

    if (str == "remove") {
      cin >> a;
      bit &=~(1<<a);//a만큼 옮겨서 비트를 끈다.
    }

    if (str == "check") {
      cin >> a;
      if (bit & (1 << a))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }

    if (str == "toggle") {
      cin >> a;
      bit ^= (1 << a);
    }
    if (str == "empty") {
      bit=0;
    }
    if (str == "all") {
      bit=0xffffff;//0b가 아님???(24bit)
    }
  }
}
//1. 끌때 toggle 조심!
//2. 비트를 적용할땐 =& 아닐땐 &만