#include<bits/stdc++.h>
using namespace std;
int n;
double m;
int dp[10001]; // 최대 돈이 100.00 * 100 = 10000 이므로 크기를 10001로 설정합니다.
int c;
double p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> n >> m;
        if (n == 0 && m < 0.01) { // 0 0.00 입력 시 종료
            break;
        }

        int money_cents = round(m * 100);
        
        // DP 배열을 현재 돈의 크기만큼만 초기화합니다.
        fill(dp, dp + money_cents + 1, 0);

        for(int i = 0; i < n; i++){
            cin >> c >> p;
            int price_cents = round(p * 100);
            
            // 무한 배낭 문제는 정방향으로 순회해야 합니다.
            for(int j = price_cents; j <= money_cents; j++){
                dp[j] = max(dp[j], dp[j - price_cents] + c);
            }
        }
        cout << dp[money_cents] << "\n";
    }
    return 0;
}
//중복이 가능하기 때문에 정방향으로 돌린다.