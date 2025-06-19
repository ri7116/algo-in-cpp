#include<bits/stdc++.h>
using namespace std;
int arr[104][104];
int arr2[104][104];
int visited[104][104];
int visited2[104][104];
int l, n;
int ans;

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr2[j][i] = arr[i][j]; // arr2는 열 기준
        }
    }

    // 행 검사
    for (int i = 0; i < n; i++) {
        memset(visited[i], 0, sizeof(visited[i])); // visited 초기화
        int flag = 1;

        for (int j = 1; j < n; j++) {
            if (arr[i][j] == arr[i][j - 1]) continue;
            if (abs(arr[i][j] - arr[i][j - 1]) > 1) {
                flag = 0;
                break;
            }
            // 오르막 (현재가 더 높음)
            if (arr[i][j] - arr[i][j - 1] == 1) {
                bool ok = true;
                for (int k = 0; k < l; k++) {
                    int idx = j - 1 - k;
                    if (idx < 0 || arr[i][idx] != arr[i][j - 1] || visited[i][idx]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) { flag = 0; break; }
                for (int k = 0; k < l; k++) visited[i][j - 1 - k] = 1;
            }
            // 내리막 (현재가 더 낮음)
            else if (arr[i][j - 1] - arr[i][j] == 1) {
                bool ok = true;
                for (int k = 0; k < l; k++) {
                    int idx = j + k;
                    if (idx >= n || arr[i][idx] != arr[i][j] || visited[i][idx]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) { flag = 0; break; }
                for (int k = 0; k < l; k++) visited[i][j + k] = 1;
            }
        }
        if (flag) ans++;
    }

    // 열 검사
    for (int i = 0; i < n; i++) {
        memset(visited2[i], 0, sizeof(visited2[i]));
        int flag = 1;

        for (int j = 1; j < n; j++) {
            if (arr2[i][j] == arr2[i][j - 1]) continue;
            if (abs(arr2[i][j] - arr2[i][j - 1]) > 1) {
                flag = 0;
                break;
            }
            // 오르막 (현재가 더 높음)
            if (arr2[i][j] - arr2[i][j - 1] == 1) {
                bool ok = true;
                for (int k = 0; k < l; k++) {
                    int idx = j - 1 - k;
                    if (idx < 0 || arr2[i][idx] != arr2[i][j - 1] || visited2[i][idx]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) { flag = 0; break; }
                for (int k = 0; k < l; k++) visited2[i][j - 1 - k] = 1;
            }
            // 내리막 (현재가 더 낮음)
            else if (arr2[i][j - 1] - arr2[i][j] == 1) {
                bool ok = true;
                for (int k = 0; k < l; k++) {
                    int idx = j + k;
                    if (idx >= n || arr2[i][idx] != arr2[i][j] || visited2[i][idx]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) { flag = 0; break; }
                for (int k = 0; k < l; k++) visited2[i][j + k] = 1;
            }
        }
        if (flag) ans++;
    }
    cout << ans;
}
