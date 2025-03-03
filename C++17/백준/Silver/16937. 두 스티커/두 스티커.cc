#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;

    // 입력받은 작은 직사각형들 중, 큰 판에 들어갈 수 있는 것만 저장합니다.
    vector<pii> rects;
    for (int i = 0; i < n; i++){
        int r, c;
        cin >> r >> c;
        // 회전 가능한 조건으로 판에 들어갈 수 있는지 검사합니다.
        if ((r <= h && c <= w) || (r <= w && c <= h))
            rects.push_back({r, c});
    }
    
    int mx = 0;
    int vs = rects.size();
    // 두 개의 직사각형을 선택합니다.
    for (int i = 0; i < vs; i++){
        for (int j = i+1; j < vs; j++){
            // 직사각형 i의 크기 (a, b)와 직사각형 j의 크기 (c, d)
            int a = rects[i].first, b = rects[i].second;
            int c = rects[j].first, d = rects[j].second;
            // 두 직사각형의 넓이 합
            int area = a * b + c * d;
            
            // 총 8가지 경우를 아래와 같이 명시적으로 검사합니다.
            // 각 직사각형은 (원래, 회전 후) 두 가지 형태가 있습니다.
            // 그리고 배치는 가로 배치와 세로 배치 두 가지 방식입니다.
            
            // [옵션 1] rect1: (a, b), rect2: (c, d)
            {
                int r1 = a, c1 = b;
                int r2 = c, c2 = d;
                // 가로 배치: 두 직사각형을 좌우로 붙이기
                if (max(r1, r2) <= h && (c1 + c2) <= w)
                    mx = max(mx, area);
                // 세로 배치: 두 직사각형을 위아래로 붙이기
                if ((r1 + r2) <= h && max(c1, c2) <= w)
                    mx = max(mx, area);
            }
            
            // [옵션 2] rect1: (a, b), rect2: (d, c) -> 두 번째 직사각형을 회전
            {
                int r1 = a, c1 = b;
                int r2 = d, c2 = c;
                if (max(r1, r2) <= h && (c1 + c2) <= w)
                    mx = max(mx, area);
                if ((r1 + r2) <= h && max(c1, c2) <= w)
                    mx = max(mx, area);
            }
            
            // [옵션 3] rect1: (b, a) -> 첫 번째 직사각형 회전, rect2: (c, d)
            {
                int r1 = b, c1 = a;
                int r2 = c, c2 = d;
                if (max(r1, r2) <= h && (c1 + c2) <= w)
                    mx = max(mx, area);
                if ((r1 + r2) <= h && max(c1, c2) <= w)
                    mx = max(mx, area);
            }
            
            // [옵션 4] rect1: (b, a), rect2: (d, c) -> 양쪽 모두 회전
            {
                int r1 = b, c1 = a;
                int r2 = d, c2 = c;
                if (max(r1, r2) <= h && (c1 + c2) <= w)
                    mx = max(mx, area);
                if ((r1 + r2) <= h && max(c1, c2) <= w)
                    mx = max(mx, area);
            }
        }
    }
    
    cout << mx;
    return 0;
}
