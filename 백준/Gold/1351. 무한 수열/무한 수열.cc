#include<bits/stdc++.h>
using namespace std;

long long n,p,q;
map<long long,long long> dp;
long long w(long long n){
    if(n == 0) return 1;
    
    //만약 dp가 이미 계산된 값이 있다면 그 값을 반환
    if(dp.find(n) != dp.end()) return dp[n];
    //없으면 계산해
    return dp[n] = w(n/p) + w(n/q);
}





int main(){
    cin>> n >> p >> q;
    cout <<w(n);
}

//bottom up 저격문제
//dp를 이용한 모든 dp를 구하는 문제