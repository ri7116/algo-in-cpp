#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[20004];
long long ans;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){ 
    cin>>arr[i];
  }
  sort(arr,arr+n);
  for(int i=0;i<n;i++){
  // long long i=9;  
  //cout<<"i : "<<i<<endl;
  vector<long long> v;
  for(int j=0;j<n;j++){
    if(i==j) continue;
    v.push_back(arr[j]);
  }

    long long st=0;
    long long ed=n-2;
    while(st<ed){
      long long SUM=v[st]+v[ed];
      if(SUM<arr[i]){
        // cout<<"q"<<endl;
        // cout<<"st : "<<st<<endl;
        // cout<<"ed : "<<ed<<endl;
        // cout<<"sum : "<<SUM<<endl;
        st++;
      }
      else if(SUM>arr[i]){
        // cout<<"w"<<endl;
        // cout<<"st : "<<st<<endl;
        // cout<<"ed : "<<ed<<endl;
        // cout<<"sum : "<<SUM<<endl;
        ed--;
      }
      else{
        // cout<<"e"<<endl;
        // cout<<"st : "<<st<<endl;
        // cout<<"ed : "<<ed<<endl;
        // cout<<"sum : "<<SUM<<endl;
        // cout<<"arr[i] : "<<arr[i]<<endl;
        ans++;
        break;
      }
    }
  }
  cout<<ans;
}
