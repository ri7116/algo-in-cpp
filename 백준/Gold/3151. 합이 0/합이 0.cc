#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10004];
long long ans;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int xy=arr[i]+arr[j];
      //cout<<upper_bound(arr+j+1,arr+n,-xy)-lower_bound(arr+j+1,arr+n,-xy)<<endl;
      ans+=upper_bound(arr+j+1,arr+n,-xy)-lower_bound(arr+j+1,arr+n,-xy);
    }
  }
  cout<<ans;
}
//포인터 간의 차는 idx 차이이