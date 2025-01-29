#include <iostream>  // 표준 입출력 라이브러리 포함
using namespace std; // std 네임스페이스 사용

int main() {
    long long N;  // 돌의 개수 (최대 10^18)
    cin >> N;  // 사용자 입력 받기
    cout << (N & 1 ? "SK\n" : "CY\n");  // 홀수이면 SK, 짝수이면 CY 출력
}
//해설 보고 이해함