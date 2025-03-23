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
//참조한 코드
// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int main () {
    
//     string a, b;
//     vector <int> v;
    
//     cin >> a >> b;
    
//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());
    
//     if (a.size() < b.size())
//         swap(a, b);
    
//     for(int i=0; i<b.size(); i++){
//         int A = a[i] - '0';
//         int B = b[i] - '0';
//         v.push_back(A+B);
//     }
//     for(int i=b.size(); i<a.size(); i++){
//         v.push_back(a[i] - '0');
//     }
    
//     for(int i=0; i<v.size(); i++){
//         if(v[i] >= 10) {
//             if(i == v.size()-1){
//                 v.push_back(0);
//             }
//             v[i+1]++;
//             v[i] -= 10;
//         }
//     }
    
//     reverse (v.begin(), v.end());
//     for(int i=0; i<v.size(); i++){
//         cout << v[i];
//     }
        
//     return 0;
// }