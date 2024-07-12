#include<bits/stdc++.h>
using namespace std;
long long a[94];

int main(){
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=90;i++){
        a[i]=a[i-1]+a[i-2];
    }
    int n;
    cin>>n;
    cout<<a[n];
}