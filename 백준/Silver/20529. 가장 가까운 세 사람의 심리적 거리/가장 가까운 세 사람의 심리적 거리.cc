#include<bits/stdc++.h>
using namespace std;
int k,n;
string str[1000004];
int visited[33];
int arr[33];
int ans=9876543210;

void fuc(int depth,int cur){
  if(depth==3){
    int tmp=0;
    string a=str[arr[0]];
    string b=str[arr[1]];
    string c=str[arr[2]];
    
    for(int i=0;i<4;i++){
      if(a[i]!=b[i]) tmp++;
    }

    for(int i=0;i<4;i++){
      if(b[i]!=c[i]) tmp++;
    }

    for(int i=0;i<4;i++){
      if(a[i]!=c[i]) tmp++;
    }
    ans=min(ans,tmp);
    
    return;
  }
  

  for(int i=cur;i<n;i++){
    if(visited[i]) continue;
    arr[depth]=i;
    visited[i]=1;
    fuc(depth+1,i+1);
    visited[i]=0;
  }
}


int main(){
  cin>>k;
  while(k--){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>str[i];
    }

    if(n>=33) {
      cout<<0<<endl;
      continue;
    }
    fuc(0,0);
    cout<<ans<<endl;
    ans=9876543210;
  }
}

// 브루트포스 알고리즘에서 시간초과가 날 거 같으면 비둘기집의 원리를 한번 생각해보자!!