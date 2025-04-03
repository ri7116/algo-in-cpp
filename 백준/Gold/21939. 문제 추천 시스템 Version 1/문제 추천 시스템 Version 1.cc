#include<bits/stdc++.h>
using namespace std;

int n;
int q;

set<pair<int,int>> s;
map<int,int> mp;


int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    mp[a]=b;
    s.insert({b,a});
  }
  cin>>q;
  for(int i=0;i<q;i++){
    string a;
    cin>>a;
    if(a=="add"){
      int b;
      int c;
      cin>>b>>c;
      s.insert({c,b});
      mp[b]=c;
      continue;
    }
    if(a=="recommend"){
      int b;
      cin>>b;
      if(b==1){
        cout<<prev(s.end())->second<<endl;
        continue;
      }
      if(b==-1){
        cout<<s.begin()->second<<endl;
        continue;
      }
    }
    if(a=="solved"){
      int b;
      cin>>b;
      int c=mp[b];
      s.erase({c,b});
    }
  }
}
//1. rbegin 진짜 마지막 
//2. end()하면 틀림 마지막은 끝 다음이여 하지만 prev,next넣어도 틀림