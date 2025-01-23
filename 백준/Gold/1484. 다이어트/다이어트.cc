  #include<bits/stdc++.h>
  using namespace std;
  int r;
  queue <int> q;
  int main(){
    cin>>r;
    int st=1, ed=1;
    while(st<=1000000 and ed<=1000000){
      int result=pow(ed,2)-pow(st,2);
      if(result<r) ed++;
      if(result>r) st++;
      if(result==r) {
        q.push(ed);
        ed++;
      }
    }
    if(!q.empty()){
    while(!q.empty()){
      cout<<q.front();
      cout<<'\n';
      q.pop();
    }
    }
    else{
      cout<<"-1";
    }
  }
