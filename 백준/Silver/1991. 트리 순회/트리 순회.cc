#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30];
int rc[30];

void pre(int cur){
  cout<<char(cur+'A'-1);
  if(lc[cur]!=0) pre(lc[cur]);
  if(rc[cur]!=0) pre(rc[cur]); 
}
void md(int  cur){
  if(lc[cur]!=0) md(lc[cur]);
  cout<<char(cur+'A'-1);
  if(rc[cur]!=0) md(rc[cur]); 
}
void af(int  cur){
  if(lc[cur]!=0) af(lc[cur]);
  if(rc[cur]!=0) af(rc[cur]); 
  cout<<char(cur+'A'-1);
}

int main(){
  cin.tie(0);
  cin>>n;
  char p,l,r;
  for(int i=0;i<n;i++){
  cin>>p>>l>>r;
    if(l!='.') lc[p-'A'+1]=l-'A'+1;
    if(r!='.') rc[p-'A'+1]=r-'A'+1;

  }
  pre(1);
  cout<<'\n';
  md(1);
  cout<<'\n';
  af(1);
}

// void preorder(int cur){
//   cout << char(cur+'A'-1);
//   if(lc[cur] != 0) preorder(lc[cur]);
//   if(rc[cur] != 0) preorder(rc[cur]);  
// }

// void inorder(int cur){
//   if(lc[cur] != 0) inorder(lc[cur]);
//   cout << char(cur+'A'-1);
//   if(rc[cur] != 0) inorder(rc[cur]);
// }

// void postorder(int cur){
//   if(lc[cur] != 0) postorder(lc[cur]);
//   if(rc[cur] != 0) postorder(rc[cur]);
//   cout << char(cur+'A'-1);  
// }

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n;
//   for(int i = 1; i <= n; i++){
//     char c,l,r; // cur, left, right
//     cin >> c >> l >> r;
//     if(l != '.') lc[c-'A'+1] = l-'A'+1;
//     if(r != '.') rc[c-'A'+1] = r-'A'+1;
//   }
//   preorder(1); cout << '\n';
//   inorder(1); cout << '\n';
//   postorder(1); cout << '\n';  
// }