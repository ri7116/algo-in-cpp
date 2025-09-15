#include<bits/stdc++.h>
using namespace std;
long long arr[1000004];
long long a,b;

int main(){
    cin>>a;
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    for(int i=3;i<=100;i++){
        arr[i]=arr[i-2]+arr[i-3];
    }

    while(a--){
        cin>>b;
        cout<<arr[b]<<endl;
    }
}