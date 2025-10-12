#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int ans = 0;
    for(int i=0;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(i==0 and j==0) {
                dp[0][0]= triangle[0][0];
                ans=max(ans,dp[i][j]);
                continue;
            }
            if(j==triangle[i].size()-1){
                dp[i][j]=dp[i-1][triangle[i].size()-2]+triangle[i][j];
                ans=max(ans,dp[i][j]);
                continue;
            }
            if(j==0){
                dp[i][j]=dp[i-1][j]+triangle[i][j];
                ans=max(ans,dp[i][j]);
                continue;
            }
            
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            ans=max(ans,dp[i][j]);
        }
    }

    return ans;
}