#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 내림차순 정렬: 큰 작업부터 배정
    sort(arr.rbegin(), arr.rend());

    // min-heap: 각 기계의 누적 작업 시간
    priority_queue<long long, vector<long long>, greater<long long>> q;

    // 처음 M개의 작업을 각 기계에 배정
    for (int i = 0; i < m && i < n; i++) {
        q.push(arr[i]);
    }

    // 나머지 작업: 가장 빨리 끝나는 기계(top)에게 배정
    for (int i = m; i < n; i++) {
        long long t = q.top(); q.pop();
        q.push(t + arr[i]);
    }

    // 전체 소요시간 = 가장 늦게 끝나는 기계의 누적 시간
    long long ans = 0;
    while (!q.empty()) {
        ans = max(ans, q.top());
        q.pop();
    }

    cout << ans;
}
