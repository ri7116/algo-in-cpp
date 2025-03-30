#include <iostream>
#include <algorithm>
using namespace std;

int n, s, m;
int arr[1004];
bool dp[54][1004];

int main(){
    cin >> n >> s >> m;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    
    dp[0][s] = true;
    for(int i = 1; i <= n; i++){
        for(int v = 0; v <= m; v++){
            if(dp[i-1][v]){
                if(v + arr[i] <= m)
                    dp[i][v + arr[i]] = true;
                if(v - arr[i] >= 0)
                    dp[i][v - arr[i]] = true;
            }
        }
    }
    
    int ans = -1;
    for(int v = 0; v <= m; v++){
        if(dp[n][v])
            ans = max(ans, v);
    }
    cout << ans;
}
