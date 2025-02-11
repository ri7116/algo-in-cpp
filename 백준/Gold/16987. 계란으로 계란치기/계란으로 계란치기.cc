#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector<pair<int, int>> _map;
vector<pair<int, int>> v;
int ans = 0;

void fuc(int m) {
    if (m == n) { // 모든 계란을 다 선택했을 때 결과 갱신
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (_map[i].X <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    // 현재 계란이 이미 깨졌다면 다음 계란으로 이동
    if (_map[m].X <= 0) {
        fuc(m + 1);
        return;
    }

    bool hit = false; // 적어도 한 번 때렸는지 확인
    for (int i = 0; i < n; i++) {
        if (m == i) continue;   // 자기 자신은 때릴 수 없음
        if (_map[i].X <= 0) continue; // 상대 계란이 깨졌다면 스킵

        // 계란 부딪히기
        _map[i].X -= v[m].Y;
        _map[m].X -= v[i].Y;

        fuc(m + 1); // 다음 계란 선택

        // 원래 상태로 복구 (백트래킹)
        _map[i].X += v[m].Y;
        _map[m].X += v[i].Y;

        hit = true; // 한 번이라도 부딪힌 경우 체크
    }

    // 한 번도 부딪히지 않았다면 그냥 다음 계란으로 이동
    if (!hit) fuc(m + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        _map.push_back({a, b});
        v.push_back({a, b});
    }

    fuc(0);
    cout << ans;
}
