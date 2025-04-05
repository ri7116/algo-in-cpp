#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[10000004];
long long buset;
long long ans=-1;
long long realans=-1;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>buset;
  sort(arr,arr+n);
  long long st=0;
  long long ed=arr[n-1];
  while(st<=ed){
    //cout<<st<<" "<<ed<<endl;
    long long cut= (st+ed)/2;
    long long SUM=0;
    for(int i=0;i<n;i++){
      if(arr[i]<=cut) SUM+=arr[i];
      else SUM+=cut;
    }
    if(SUM<=buset){
      ans=max(ans,cut);
      st=cut+1;
    }
    else{
      ed=cut-1;
    }
    //cout<<"cut :"<<cut<<endl;
    //cout<<"SUM :"<<SUM<<endl;
  }
  cout<<ans;
}



