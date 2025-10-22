#include <string>
#include <vector>

using namespace std;
int ans = 0; // 전역 변수 ans

void f(int SUM, int idx, int plus, vector<int>& numbers, int target) {
    
    // 1. 현재 idx의 숫자를 SUM에 반영
    int nSUM = 0;
    if (plus == 1) nSUM = SUM + numbers[idx];
    else nSUM = SUM - numbers[idx];

    // 2. 만약 지금 처리한 것이 마지막 숫자(idx == size - 1)였다면,
    //    nSUM이 target인지 검사하고 재귀를 종료한다.
    if (idx == numbers.size() - 1) {
        if (nSUM == target) {
            ans++;
        }
        return; // 더 이상 재귀 호출을 하지 않음
    }

    // 3. 마지막 숫자가 아니었다면, 다음 숫자를 위해 재귀 호출
    f(nSUM, idx + 1, 1, numbers, target);
    f(nSUM, idx + 1, 0, numbers, target);
}

int solution(vector<int> numbers, int target) {
    ans = 0; // ans를 0으로 초기화 (테스트 케이스마다 초기화 필요)

    f(0, 0, 1, numbers, target); // 0번째 원소를 더하는 경로 시작
    f(0, 0, 0, numbers, target); // 0번째 원소를 빼는 경로 시작
    
    return ans; // 이제 2로 나누지 않음
}