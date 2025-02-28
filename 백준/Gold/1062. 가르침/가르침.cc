#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[26];  // 'a' ~ 'z' 알파벳 체크
int ans;
vector<string> str;

void fuc(int depth, int cur) {
    if (depth == k) {  // K개의 글자를 선택했을 때
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool readable = true;
            for (char c : str[i]) {
                if (!arr[c - 'a']) {
                    readable = false;
                    break;
                }
            }
            if (readable) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for (int i = cur; i < 26; i++) {
        if (arr[i]) continue;  // 이미 배운 문자면 스킵
        arr[i] = 1;
        fuc(depth + 1, i + 1);
        arr[i] = 0;
    }
}

int main() {
    cin >> n >> k;
    if (k < 5) {  // 'a', 'n', 't', 'i', 'c'도 못 배우면 읽을 수 있는 단어가 없음
        cout << 0 << endl;
        return 0;
    }

    // 필수 문자 'a', 'n', 't', 'i', 'c' 배우기
    arr['a' - 'a'] = 1;
    arr['n' - 'a'] = 1;
    arr['t' - 'a'] = 1;
    arr['i' - 'a'] = 1;
    arr['c' - 'a'] = 1;
    
    k -= 5;  // 필수 문자 5개를 배웠으므로 남은 배울 수 있는 문자 개수 감소

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }

    fuc(0, 0);
    cout << ans << endl;
}
