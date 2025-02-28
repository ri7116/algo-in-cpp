#include <bits/stdc++.h>
using namespace std;

int arr[50]; // 1000 이하의 삼각수는 최대 약 44개
int check;

void fuc(int depth, int sum, int input, int idx) {
    if (depth == 3) {
        if (sum == input) check = 1;
        return;
    }

    for (int i = 1; i < idx; i++) { // 삼각수 선택
        fuc(depth + 1, sum + arr[i], input, idx);
        if (check) return;  // 정답을 찾으면 종료 (불필요한 탐색 방지)
    }
}

int main() {
    int tmp = 1, limit = 1;
    while (tmp * (tmp + 1) / 2 <= 1000) {
        arr[limit++] = tmp * (tmp + 1) / 2;
        tmp++;
    }

    int k;
    cin >> k;
    while (k--) {
        int a;
        cin >> a;
        check = 0;
        fuc(0, 0, a, limit); // idx = 삼각수 개수
        cout << check << endl;
    }
}
