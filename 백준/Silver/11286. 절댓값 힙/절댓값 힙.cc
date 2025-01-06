#include<bits/stdc++.h>
using namespace std;

int heap[100000];
int sz=0;

int front(){
  return heap[1];
}
void push(int x){
  sz++;
  heap[sz]=x;
  int idx=sz;
  while(idx>1){
    if(abs(heap[idx])<abs(heap[idx/2])) swap(heap[idx],heap[idx/2]); //현재 절대값이 부모의 절대값보다 작으면 스왑
    if(abs(heap[idx])==heap[idx/2] and heap[idx]<heap[idx/2]) swap(heap[idx],heap[idx/2]);//두 절대값이 같고 현재 값이 작 으면 스왑
    idx=idx/2;
  }
}
void pop(){
  heap[1]=heap[sz];
  sz--;
  int idx=1;
  while(sz>=2*idx){
    int rc=2*idx+1;
    int lc=2*idx;
    int min= lc;
    
    if(rc<=sz and rc and abs(heap[rc])<abs(heap[lc])) min=rc;
    //!!좌우의 절대값이 같은 경우를 무시 했다. !!이거 고쳐야 됨 
    if(rc<=sz and rc and abs(heap[rc])==abs(heap[lc])and heap[rc]<heap[lc] ) min=rc;
    if(rc<=sz and rc and abs(heap[rc])==abs(heap[lc])and heap[rc]>heap[lc]) min=lc;
    
    if(abs(heap[idx])<=abs(heap[min])) {//종료 조건의 문제 인가?
      if(abs(heap[idx])==abs(heap[min]) and heap[idx]>heap[min]) {
        swap(heap[idx], heap[min]);
        idx=min;
        continue;
      }
      else{
        break;
      }
    }
    if(abs(heap[idx])==abs(heap[min]) and heap[idx]>heap[min]){
     swap(heap[idx], heap[min]);
      idx=min;
      continue;
    }
    swap(heap[idx], heap[min]);
    idx=min;
    continue;
  }
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int t;
    cin>>t;
    if(t==0){
      if(sz==0) cout<<0<<"\n";
      else {
        cout<<front();
        cout<<"\n";
        pop();
         // for(int i=1;i<10;i++){
         //   cout<<heap[i]<<" ";
         // }
         // cout<<endl;
      }
    }
    else{
      push(t);
    }
  }
  // for(int i=1;i<10;i++){
  //   cout<<heap[i]<<" ";
  // }
  // push(5);
  // push(-1);
  // push(4);
  // push(1);
  // pop();
  // for(int i=1;i<10;i++){
  //   cout<<heap[i]<<" ";
  // }
  // cout<<endl;
  // push(999);
  // push(7);
  // for(int i=1;i<10;i++){
  //   cout<<heap[i]<<" ";
  // }
  // cout<<endl;
  // pop();
  // for(int i=1;i<10;i++){
  //   cout<<heap[i]<<" ";
  // }
}
