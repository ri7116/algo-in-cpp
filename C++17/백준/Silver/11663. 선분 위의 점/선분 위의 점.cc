#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[100004];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int tmp=lower_bound(arr,arr+n,b)-lower_bound(arr,arr+n,a);
        if(arr[lower_bound(arr,arr+n,b)-arr]==b) tmp++;
        cout<<tmp<<'\n';
    }
}
