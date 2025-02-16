#include <bits/stdc++.h>
using namespace std;

string str;
int D[1000000]; // 배열 크기 줄임 (메모리 절약)

int main() {
    cin >> str;

    if (str[0] == '0') {  // 첫 글자가 0이면 불가능한 암호
        cout << 0;
        return 0;
    }

    D[0] = 1;  // 첫 번째 글자는 해석 가능하므로 초기값 설정

    for (int i = 1; i < str.size(); i++) {
        if (str[i] != '0') {  
            D[i] = D[i - 1] % 1000000;  // 1자리 숫자로 해석
        }

        int two_digit = (str[i - 1] - '0') * 10 + (str[i] - '0');  // 2자리 숫자

        if (10 <= two_digit && two_digit <= 26) {
            if (i == 1) {
                D[i] = (D[i] + 1) % 1000000;  // 두 번째 자리의 경우, 두 가지 방법이 있음
            } else {
                D[i] = (D[i] + D[i - 2]) % 1000000;  // 두 자리로 해석한 경우 더하기
            }
        }

        // 예외 처리: '00'과 같이 해석 불가능한 경우
        if (str[i] == '0' && (str[i - 1] != '1' && str[i - 1] != '2')) {
            cout << 0;
            return 0;
        }
    }

    cout << D[str.size() - 1] % 1000000;
}
//코드보고 공부함 나중에 다시 풀기