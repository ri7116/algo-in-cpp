#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> score;
vector<int> dp; // 메모이제이션 배열

// solve(k): k번째 계단까지의 최대 점수를 반환하는 함수
int solve(int k) {
    // 기저 사례(Base Case): 시작점을 벗어나면 0점
    if (k <= 0) return 0;
    
    // 이미 계산된 값이면 바로 반환
    if (dp[k] != -1) return dp[k];

    // 점화식:
    // 1. (k-2)에서 두 칸 점프해서 온 경우
    int path1 = solve(k - 2) + score[k];
    
    // 2. (k-3)에서 (k-1)을 거쳐 한 칸 올라온 경우
    int path2 = solve(k - 3) + score[k - 1] + score[k];

    // 두 경우 중 더 큰 값을 저장하고 반환
    return dp[k] = max(path1, path2);
}

int main() {
    cin >> n;
    score.assign(n + 1, 0);
    dp.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    // dp 배열의 초기값 설정 (재귀가 멈출 수 있는 기반)
    dp[0] = 0;
    dp[1] = score[1];
    if (n >= 2) {
        dp[2] = score[1] + score[2];
    }

    cout << solve(n) << endl;

    return 0;
}