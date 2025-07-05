#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d[400];


int main(){ 
    cin>>n;
    d[0]=1;
    d[1]=0;
    d[2]=3;
    d[3]=0;
    for(int i=4;i<=n;i+=2){
        d[i]+=d[i-2]*3;
        for(int j=i-4;j>=0;j-=2){
            d[i]+=d[j]*2;
        }
    }
    cout<<d[n];
}