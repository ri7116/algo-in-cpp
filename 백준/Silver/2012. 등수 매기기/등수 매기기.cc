#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[500004];
long long ans;
long long cnt=1;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        ans+=abs(arr[i]-cnt);
        cnt++;
    }
    cout<<ans;
}