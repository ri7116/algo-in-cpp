#include <iostream>

using namespace std;
#define ll long long
#define mod (int)1e9

int dp[101][10][1 << 10] = { 0 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i < 10; i++)
    {
        dp[1][i][1 << i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < (1 << 10); k++)
            {
                if (j == 0) dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % mod;
                else if (j == 9) dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % mod;
                else dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % mod;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        ans = (ans + dp[n][i][(1 << 10) - 1]) % mod;
    }

    cout << ans;
}