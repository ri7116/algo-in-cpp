#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, t, want, n = 0, cnt = 0, res = 0;
	cin >> a >> t >> want;
	while (true) {
		n++; //라운드
		vector<int> what{ 0,1,0,1 }; //0뻔 1데기
		for (int i = 1; i <= n + 1; i++) what.push_back(0); //뻔 추가
		for (int i = 1; i <= n + 1; i++) what.push_back(1); //데기 추가
		for (int i = 0; i < what.size(); i++) {
			if (what[i] == want) cnt++; //등장 횟수 카운트
			if (cnt == t) {
				cout << res;
				return 0;
			}
			res++; //몇번째 사람인지 센다
			res %= a;
		}
		what.clear();
	}
}
//벡터에 추가하고 반복문으로 cnt