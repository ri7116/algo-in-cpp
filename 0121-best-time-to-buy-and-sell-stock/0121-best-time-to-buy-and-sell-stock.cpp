
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[100004];
        int ans=0;  
        dp[0]=prices[0];      
        for(int i=1;i<prices.size();i++){
            if(prices[i]<dp[i-1]) dp[i]=prices[i];
            else dp[i]=dp[i-1];
            ans=max(ans,prices[i]-dp[i-1]);
        }
        return ans;
    }
};