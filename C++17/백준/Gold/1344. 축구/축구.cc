#include <bits/stdc++.h>
using namespace std;

// 조합 함수
double comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    double res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

// 18 이하의 소수: 2, 3, 5, 7, 11, 13, 17
bool is_prime[19] = {
    false, false, true, true, false, true, false, true, false, false, false,
    true,  false, true, false, false, false, true,  false
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double A, B;
    cin >> A >> B;
    double a = A / 100.0, b = B / 100.0;

    double pA_non_prime = 0.0;
    double pB_non_prime = 0.0;

    // 각 팀이 소수가 아닌 골을 넣을 확률을 계산
    for (int i = 0; i <= 18; ++i) {
        if (!is_prime[i]) {
            double prob = comb(18, i);
            pA_non_prime += prob * pow(a, i) * pow(1.0 - a, 18 - i);
            pB_non_prime += prob * pow(b, i) * pow(1.0 - b, 18 - i);
        }
    }

    // 최종 확률 = 1 - (두 팀 모두 소수 골을 넣지 못할 확률)
    double ans = 1.0 - (pA_non_prime * pB_non_prime);

    cout << fixed << setprecision(16) << ans;
    return 0;
}