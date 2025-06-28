#include <bits/stdc++.h>
using namespace std;
int t;
int w;
int dp[1004][44][44];
int arr[1004];
int INF=-987654321;
int ans=-987654321;

int solve(int t,int position, int w){
    //기저사례
    if(t<=0) return 0;
    if(w<=0) return 0;
    if(t==1){
        if(position==1 && arr[1]==1 && w>=1) return 1;  // 1번에서 시작, 1번에서 떨어짐, 이동 없음
        if(position==2 && arr[1]==2 && w>=2) return 1;  // 2번으로 이동, 2번에서 떨어짐, 1번 이동
        return 0;
    }
    //계산되어 있으면 넘어가
    if(dp[t][position][w]!=-1) return dp[t][position][w];
    //계산해
    //떨어지는 위치
    // dp[t][1][w]= max(w(t-1,2,w-1)+1, w(t-1,1,w)+1);
    // dp[t][2][w]= max(w(t-1,1,w-1)+1, w(t-1,2,w)+1);
    // return max(dp[t][1][w],dp[t][2][w])
    if(arr[t]==1){
        // 1번에서 자두가 떨어짐
        if(position==1){
            // 1번 위치에 있음 - 받을 수 있음
            return dp[t][1][w]= max(solve(t-1,1,w), solve(t-1,2,w-1)) + 1;
        }
        else{
            // 2번 위치에 있음 - 받을 수 없음
            return dp[t][2][w]= max(solve(t-1,1,w-1), solve(t-1,2,w));
        }
    }
    else{
        // 2번에서 자두가 떨어짐
        if(position==1){
            // 1번 위치에 있음 - 받을 수 없음
            return dp[t][1][w]= max(solve(t-1,1,w), solve(t-1,2,w-1));
        }
        else{
            // 2번 위치에 있음 - 받을 수 있음
            return dp[t][2][w]= max(solve(t-1,1,w-1), solve(t-1,2,w)) + 1;
        }
    }
}


int main(){
    memset(dp, -1, sizeof(dp));
    cin >> t >> w;
    for(int i=1;i<=t;i++){
        cin>>arr[i];
    }
    
    // 모든 이동 횟수에서 최대값 찾기 (1부터 w+1까지 = 실제 0부터 w번 이동)
    for(int moves=1; moves<=w+1; moves++){
        ans = max(ans, solve(t, 1, moves));
        ans = max(ans, solve(t, 2, moves));
    }
    
    cout << ans << endl;
    return 0;
}
