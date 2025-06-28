#include <iostream>
#include <vector>
using namespace std;

// 메모이제이션용 배열
vector<int> dp(46, -1); // n ≤ 45

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    // 이미 계산된 값이면 반환
    if (dp[n] != -1) return dp[n];
    // 계산 후 배열에 저장
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << '\n';
    return 0;
}