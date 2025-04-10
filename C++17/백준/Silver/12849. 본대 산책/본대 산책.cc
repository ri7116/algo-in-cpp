#include<bits/stdc++.h>
using namespace std;

long long d[9];


int main(){
    long long t;
    cin>>t;
    d[1]=1;
    while(t--){
        long long a1=d[1];
        long long a2=d[2];
        long long a3=d[3];
        long long a4=d[4];
        long long a5=d[5];
        long long a6=d[6];
        long long a7=d[7];
        long long a8=d[8];
        d[1]=(a2+a8)%1000000007;
        d[2]=(a1+a8+a3)%1000000007;
        d[3]=(a2+a8+a4+a7)%1000000007;
        d[4]=(a3+a5+a7)%1000000007;
        d[5]=(a4+a6)%1000000007;
        d[6]=(a5+a7)%1000000007;
        d[7]=(a3+a4+a6+a8)%1000000007;
        d[8]=(a1+a2+a3+a7)%1000000007;
    }
    cout<<d[1];
}
//1. DP
//2. 혼자 였으면 절대 못맞춤 