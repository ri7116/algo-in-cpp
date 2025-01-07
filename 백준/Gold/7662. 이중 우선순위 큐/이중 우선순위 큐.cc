#include<iostream>
#include<set>
using namespace std;
int n, m, b;
char a;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n; //n번 반복
	while (n--) {
		cin >> m;
		multiset <int> mtset;//set에 중복이 가능합니다! 저장은 이진검색트리에 주의!
		while (m--) {
			cin >> a >> b;
			if (a == 'I') {//삽입
				mtset.insert(b);
			}
			else {//삭제
				if (mtset.empty()) continue;
				if (b == -1) {
					mtset.erase(mtset.begin());//맨 앞 삭제 s.erase(it) 이터레이터에 주의
				}
				else {
					mtset.erase(prev(mtset.end()));//맨 뒤 최소값 삭제 (x)틀린 코드1
					//auto it = mtset.end();(x)틀린코드2
					//it--;
					//mtset.erase(it);
				}
				//else {
				//	mtset.erase(mtset.lower_bound(b));//처음나온b를 삭제시키깅~
				//}
			}
		}
		if (mtset.empty()) {//비어 있다면
			cout << "EMPTY" << '\n';
		}
		else {
			cout<<* (prev(mtset.end())) <<" "<< *(mtset.begin()) << '\n';
		}
	}
}