#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[14];
int cnt;

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>-1;i--){
        if(arr[i]>k or k==0) continue;
        cnt+=k/arr[i];
        //cout<<"cnt : "<<cnt<<endl;
        k=k%arr[i];
        //cout<<"k : "<<k<<endl;
    }
    cout<<cnt;
}