
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int num[15];
vector<pair<int,int>> tmp;// 사용유무, 연산자(11 22 33 44 + - * /)
int _min=+2100000000;
int _max=-2100000000;
int cnt;
void fuc(int k){
  if(k==n-1){
    // cout<<"완성\n";
    // cout<<"num :";
    // for(int i=0;i<n;i++){
    //   cout<<num[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"arr :";
    // for(int i=0;i<n;i++){
    //   cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int cur=num[0];
    for(int i=0;i<n-1;i++){
      if(arr[i]==11){
        //cout<<"더하기\n";        
        cur=cur+num[i+1];
      }
      if(arr[i]==22){
        //cout<<"빼기\n";
        cur=cur-num[i+1];
      }
      if(arr[i]==33){
        //cout<<"곰셈\n";       
        //cout<<cur<<'\n';
        cur=cur*num[i+1];
        //cout<<num[2+(2*i)];
      }
      if(arr[i]==44){
        //cout<<"나누기 \n";
        cur=cur/num[i+1];
      }
    }
    //cout<<cur<<endl;
    if(cur>_max) _max=cur;
    if(cur<_min) _min=cur;
  }

  for(int i=0;i<n-1;i++){
    if(!tmp[i].first){
      arr[k]=tmp[i].second;
      tmp[i].first=1;
      fuc(k+1);
      tmp[i].first=0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    cin>>num[i];
  }  
  // for(int i=0;i<n;i++){
  //   cout<<num[i]<<" "<<endl;
  // }
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  for(int i=0;i<a;i++){
    cnt++;
    tmp.push_back({0,11});
  }
  for(int i=0;i<b;i++){
    cnt++;
    tmp.push_back({0,22});
  }
  for(int i=0;i<c;i++){
    cnt++;
    tmp.push_back({0,33});
  }
  for(int i=0;i<d;i++){
    cnt++;
    tmp.push_back({0,44});
  }
  fuc(0);
  cout<<_max<<'\n';
  cout<<_min;
}