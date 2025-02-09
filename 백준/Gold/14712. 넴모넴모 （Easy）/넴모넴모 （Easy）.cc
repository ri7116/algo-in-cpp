
#include <bits/stdc++.h>
#define endl "\n"
#define MAX 27
using namespace std;

int N, M;
bool board[MAX][MAX];
int cnt = 0; // 경우의 수를 세는 변수

void solve(int x, int y) {
    if (y > M) { // 현재 열이 범위를 넘어가면 다음 행으로 이동
        x += 1;
        y = 1;
    }
    if (x > N) { // 모든 행을 탐색한 경우 종료
        cnt++;
        return;
    }

    // 현재 위치에 넴모를 놓는 경우
    if (!(board[x - 1][y] && board[x][y - 1] && board[x - 1][y - 1])) {
        board[x][y] = true;
        solve(x, y + 1);
        board[x][y] = false; // 원상 복구
    }

    // 현재 위치에 넴모를 놓지 않는 경우
    solve(x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(board, false, sizeof(board)); // 격자판 초기화
    cin >> N >> M;
    solve(1, 1);
    cout << cnt << endl; // 최종 경우의 수 출력
    return 0;
}
//코드보고 이해함 백트래킹 + 조합