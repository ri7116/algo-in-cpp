#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[100005];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first; //입력받은 순서를 다르게 해서 따로 sort함수 설정XX
    }
    sort(arr,arr+n);
    int ans=0;
    int t=0;
    for(int i=0;i<n;i++){
        if(t>arr[i].second) continue;
        ans++;
        t=arr[i].first;
    }
    cout<<ans;
}