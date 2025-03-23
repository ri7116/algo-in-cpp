#include<bits/stdc++.h>
using namespace std;

//1. 리버스
//2. a를 자릿수 더 큰걸로
//3. 올림 + k-=10 처리
string a;
string b;
vector<int> aNum(10000000,0);
vector<int> bNum(10000000,0);
vector<int> Sum;

int main(){
  cin>>a>>b;
  //1.
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  //2.
  if(a.size()<b.size()) swap(a,b);
  for(int i=0;i<a.size();i++){
    aNum[i]=a[i]-'0';//숫자로 변환
  }
  for(int i=0;i<b.size();i++){
    bNum[i]=b[i]-'0';//숫자로 변환
  }

  // for(auto au: aNum){
  //   cout<<au<<" ";
  // }
  // cout<<endl;
 
  for(int i=0;i<a.size();i++){
 //   cout<<aNum[i]+bNum[i]<<endl;
    Sum.push_back(aNum[i]+bNum[i]);
    if(Sum[i]>=10){
      Sum[i]-=10;//10빼기
      aNum[i+1]+=1;//올림처리
    }
  }
  if(aNum[a.size()]==1) Sum.push_back(1);
  reverse(Sum.begin(),Sum.end());

  for(auto au: Sum){
    cout<<au;
  }


  
}

//reverse(a.begin(),a.end());