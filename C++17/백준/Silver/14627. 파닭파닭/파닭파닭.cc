#include <bits/stdc++.h>
using namespace std;

long long arr[1000004]; // 파 길이 저장 배열
long long n, m;         // 파 개수, 사람 수

// mid 길이로 잘랐을 때 몇 조각 나오는지 계산
long long check(long long target) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i] / target;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    long long sum = 0;
    long long mx = 0;

    // 입력 받으며 전체 길이와 최대 길이 계산
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    long long st = 1;
    long long ed = mx;
    long long res = 0;

    // 가능한 최대 파 길이 이진 탐색
    while (st <= ed) {
        long long mid = (st + ed) / 2;
        if (check(mid) >= m) {
            res = mid;        // 가능한 최대 길이 저장
            st = mid + 1;     // 더 긴 길이 탐색
        } else {
            ed = mid - 1;     // 더 짧은 길이 탐색
        }
    }

    // 최종적으로 남는 파의 양 출력
    cout << sum - res * m << '\n';
    return 0;
}
