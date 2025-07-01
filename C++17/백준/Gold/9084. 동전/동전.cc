#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        vector<int> coins(n);
        for(int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        
        int target;
        cin >> target;
        
        // dp[i] = i원을 만드는 방법의 수
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // 0원을 만드는 방법은 1가지 (아무 동전도 사용하지 않기)
        
        // 각 동전에 대해
        for(int coin : coins) {
            // 해당 동전부터 목표 금액까지
            for(int amount = coin; amount <= target; amount++) {
                dp[amount] += dp[amount - coin];
            }
        }
        
        cout << dp[target] << "\n";
    }
    
    return 0;
}