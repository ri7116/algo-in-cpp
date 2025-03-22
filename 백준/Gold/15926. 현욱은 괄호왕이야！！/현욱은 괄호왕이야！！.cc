#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int dp[200004];
stack<int> stk;
int ans;
int cnt;

int main(){
  cin>>n;
  cin>>str;

  for(int i=0;i<str.size();i++){
    if(str[i]=='(') {
      stk.push(i);
      continue;
    }
    if(str[i]==')' and stk.size()){
      dp[stk.top()]=1;
      dp[i]=1;
      //내가 궁금한게 여는 괄호가 맨위에 있으면 처음 닫는게 나오면 계속 항상 좋은 괄호가 나오나?
      //ㅇㅇ 무조건 괄호랑 만날 수 밖에 없음! 비어있지 않는다면
      stk.pop();
      continue;
    }
  }
  //dp에 가자 연속된 1이 답!;
  for(int i=0;i<str.size();i++){
    if(dp[i]==0){
      ans=max(ans,cnt);
      cnt=0;
    }
    else{
      cnt++;
    }
  }
  //cout<<ans; !틀린코드
  cout<<max(ans,cnt);
}
//1. (라면 큐에 넣는다 2. 안비어 있고 )라면 스택의 탑의 인덱스 dp를 1 3. 디피에서 1이 가장 긴 길이가 정답 
//2. cout<<max(ans,cnt); 마지막의 max값의 반영 