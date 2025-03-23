#include<bits/stdc++.h>
using namespace std;
string cmd;
string str;
int k,n;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>k;
  while(k--){
  deque<int> dq;
  
  cin>>cmd;
  cin>>n;
  cin>>str;
  int Dcnt=0;
  for(int i=0;i<cmd.size();i++){
    if(cmd[i]=='D') Dcnt++;
  }
  if(Dcnt>n){
    cout<<"error\n";
    continue;
  }

  int idx=1;
  // for(int i=1;i<2*n+1;i+=2){
  //   dq.push_back(str[i]-'0');
  // }
  
  int tdx = 0; // 명령어 인덱스
  string tm = "";
  while(str[tdx] != ']'){
      if(str[tdx] == '[')
          tdx++;
      else if(str[tdx] == ','){
        dq.push_back(stoi(tm)); // int 형 변환 후 배열에 저장
          tdx++;
          tm = "";
      }else{
          tm += str[tdx]; // 숫자 +
          tdx++;
      }
  }
  if(tm != ""){
    dq.push_back(stoi(tm)); // int 형 변환 후 배열에 저장
  }

  for(int i=0;i<cmd.size();i++){
    if(cmd[i]=='R'){
      //reverse(dq.begin(),dq.end());//시간 복잡도가 n이라 문제가 생김
      idx*=-1;

      //디버깅 나중에 삭제 해야됨
      // cout<<"R : ";
      // for(int i=0;i<dq.size();i++){
      //   cout<<dq[i]<<" ";
      // }
      // cout<<endl;
      //
    }

    if(cmd[i]=='D'){
      //cout<<"idx: "<<idx<<endl;
      if(idx==1) dq.pop_front();
      else dq.pop_back();
    }
  }

  // for(auto au:dq){
  //   cout<<au<<" ";
  // }
  // cout<<endl;
  
  cout<<"[";
  if(idx==1){
    for(int i=0;i<dq.size();i++){
      if(i==dq.size()-1){
        cout<<dq[i];
        continue;
      }
      cout<<dq[i]<<",";
    }
  }
  else{
    for(int i=0;i<dq.size();i++){
      if(i==dq.size()-1){
        cout<<dq[dq.size()-1-i];
        continue;
      }
      cout<<dq[dq.size()-1-i]<<",";
    }
  }
  cout<<"]"; 
  cout<<endl;
  }
}
//1. deque
//2. reverse O(n)는 메소드가 아니라 함수로 씀!
//3. reverse는 바로 할 필요가 없고 idx로 기억하면 됨