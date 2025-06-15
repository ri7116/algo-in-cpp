#include <bits/stdc++.h>
using namespace std;
int n;
int Map[24][24];
int visited[24][24];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int eat[24][24];
int ans;
int Size = 2;
int cur_x;
int cur_y;
// ↓ eat_cnt는 유지
int eat_cnt = 0;
// ↓ cnt, dis는 더 이상 사용할 필요 없음
// int cnt;
// int dis = 210000000;

void bfs(int cur_y,int cur_x) {
    queue<pair<int,int>> q;
    q.push({cur_y, cur_x});
    visited[cur_y][cur_x] = 1;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;            // 범위 검사
            if (Map[ny][nx] > Size) continue;                                // 너무 큰 물고기
            if (visited[ny][nx]) continue;                                   // 이미 방문
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Map[i][j];
            if (Map[i][j] == 9) {
                cur_y = i;
                cur_x = j;
                Map[i][j] = 0;
            }
        }
    }

    while (true) {
        // 0. 초기화
        // [삭제] cnt = 0;
        // [삭제] dis = 210000000;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                eat[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        // 1. 먹을 수 있는 물고기 표시 (크기만 비교)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 < Map[i][j] && Map[i][j] < Size) {
                    eat[i][j] = 1;
                }
            }
        }

        // [삭제] 이 전체 블록: 장애물로 인해 도달 불가능한 물고기까지 포함됨
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (0 < Map[i][j] and Map[i][j] < Size) {
        //             cnt++;
        //             eat[i][j] = 1;
        //         }
        //     }
        // }
        // if (cnt == 0) break;

        // 2. 거리 계산
        bfs(cur_y, cur_x);

        // 3. 먹을 수 있는 물고기 중 최단거리·위→좌 우선 선택
        int dis = INT_MAX;
        int ty = -1, tx = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] != 0 && eat[i][j] == 1) {
                    int d = visited[i][j] - 1;
                    if (d < dis
                     || (d == dis && (i < ty || (i == ty && j < tx)))) {
                        dis = d;
                        ty = i;
                        tx = j;
                    }
                }
            }
        }

        // [추가] 도달 가능한 물고기가 하나도 없으면 종료
        if (ty == -1) break;

        // 4. 물고기 먹기 및 성장
        cur_y = ty;
        cur_x = tx;
        ans += dis;
        eat_cnt++;
        if (eat_cnt == Size) {
            eat_cnt = 0;
            Size++;
        }
        Map[cur_y][cur_x] = 0;
    }

    cout << ans;
    return 0;
}
