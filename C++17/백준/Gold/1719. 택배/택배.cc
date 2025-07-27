#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, m;
int ans[201][201]; // 문제의 n 최대값은 200입니다.
int path[201][201]; // 변수명을 tmp에서 path로 변경하여 의미를 명확히 했습니다.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    // 1. 배열 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) {
                ans[i][j] = 0;
                path[i][j] = 0; // 자기 자신으로 가는 경로는 없음
            } else {
                ans[i][j] = INF;
            }
        }
    }
    
    // 2. 양방향 간선 정보 입력 (수정된 핵심 부분)
    for(int i = 0; i < m; i++){
        int from, to, w;
        cin >> from >> to >> w;
        // from -> to
        if (w < ans[from][to]) {
            ans[from][to] = w;
            path[from][to] = to;
        }
        // to -> from
        if (w < ans[to][from]) {
            ans[to][from] = w;
            path[to][from] = from;
        }
    }
    
    // 3. 플로이드-워셜 알고리즘
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(ans[i][j] > ans[i][k] + ans[k][j]){
                    ans[i][j] = ans[i][k] + ans[k][j];
                    // i에서 j로 가는 첫 경유지는 i에서 k로 가는 첫 경유지와 동일
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    
    // 4. 결과 출력
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) {
                cout << "- ";
            } else {
                cout << path[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}