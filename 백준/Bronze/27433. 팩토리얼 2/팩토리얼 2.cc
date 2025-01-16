#include<bits/stdc++.h>
using namespace std;
long long n;
long long recursive(long long n){
    if(n==1 or n==0) return 1;
    return n*recursive(n-1);
}

int main(){
    cin>>n;
    cout<<recursive(n);
}