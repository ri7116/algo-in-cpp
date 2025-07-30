#include<bits/stdc++.h>
using namespace std;
int d[1000004][3];
int n;



int main(){
    cin>>n;
    d[1][0] = 1; // 1 way to have 1 digit ending with 0
    d[1][1]=1; // 1 way to have 1 digit ending with 1
    d[1][2]=1; // 1 way to have 1 digit ending
    for(int i=2;i<=n;i++){
        d[i][0] = d[i-1][0]%9901 + d[i-1][1]%9901 + d[i-1][2]%9901; // if last digit is 0, previous can be 1 or 2
        d[i][1] = d[i-1][0]%9901 + d[i-1][2]%9901; // if last digit is 1, previous can be 0 or 2
        d[i][2] = d[i-1][0]%9901 + d[i-1][1]%9901; // if last digit is 2, previous can be 0 or 1
    }  
    cout<<(d[n][0]+d[n][1]+d[n][2])%9901<<endl; // total ways to form n digit number
}
//dp [0] 둘다 색칠x dp[1] 왼쪽색칠 dp[2] 오른쪽 색칠