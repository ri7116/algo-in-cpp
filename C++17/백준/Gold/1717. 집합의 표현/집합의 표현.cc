#include <iostream>
using namespace std;

int n, k;
int parent[1000004];

//부모 노드를 찾는 함수
int getParent(int parent[], int x) {
   if (parent[x] == x) return x;
   return parent[x] = getParent(parent, parent[x]);
}
// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
   a = getParent(parent, a);
   b = getParent(parent, b);
   if (a < b) parent[b] = a;
   else parent[a] = b;
}
// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
   a = getParent(parent, a);
   b = getParent(parent, b);
   if (a == b) return 1; // 같은 집합이면 return 1
   return 0;           // 다른 집합이면 return 0
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
   int what;
   int a, b;
   cin >> n >> k;
   for (int i = 1; i <= n; i++) {
      parent[i] = i;
   }
   while (k--) {
      cin >> what >> a >> b;
      if (what == 1) {
         if (findParent(parent, a, b)) cout << "YES\n";
         else cout << "NO\n";
      }

      else {//합치는 합수
         unionParent(parent, a, b);
      }
   }
}