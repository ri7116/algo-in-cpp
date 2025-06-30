#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1001][4][4];
int mod = 1000000;

int sol(int day, int l, int a){
    if(l == 2 || a == 3) return 0;
    if(day == n) return 1;
    
    if(dp[day][l][a] != -1) return dp[day][l][a];
    
    return dp[day][l][a] = (sol(day+1, l, 0) + sol(day+1, l+1, 0) + sol(day+1, l, a+1)) % mod;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << sol(0, 0, 0);
    return 0;
}
