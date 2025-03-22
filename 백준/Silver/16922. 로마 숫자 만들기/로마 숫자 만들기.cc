#include<bits/stdc++.h>
using namespace std;
int arr[40];
set<int> s;
int n;
//중복조합
void fuc(int depth, int cur){ 
  if(depth==n){
    int sum=0;
    for(int i=0;i<n;i++){
      if(arr[i]==0) sum+=1;
      if(arr[i]==1) sum+=5;
      if(arr[i]==2) sum+=10;
      if(arr[i]==3) sum+=50;
      //cout<<arr[i]<<" ";
    }
    //cout<<endl;
    s.insert(sum);
    
    return;
  }

  for(int i=cur;i<4;i++){
    arr[depth]=i;
    fuc(depth+1, i);
  }
}

int main(){
  cin>>n;
  fuc(0,0);
  cout<<s.size();
}
//1. 중복 조합 (depth+1,i)
//2. 조합 (depth+1, i+1)