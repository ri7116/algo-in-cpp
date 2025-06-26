#include <iostream>

using namespace std;

int N;
long long dp[31][31];

void solution() {
    for (int i = 0; i <= 30; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
                continue;
            }

            dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    while (1) {
        cin >> N;
        if (!N) break;
        cout << dp[N][0] << endl;
    }

    return 0;
}