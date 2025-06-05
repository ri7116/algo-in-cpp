#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n; //63
	long long q; //63
	
	cin >> n;
	
	q = sqrt(n); //63보다 작아짐 

	if ( (q*q) < n) {
		q++;
	}

	cout << q;

	return 0;
}
//이분탐색으로 풀면 범위를 한참 넘어가게 됨 2^62 * 2^62 = 2^124은 64비트(≈2^64−1) 범위를 한참 넘어가므로 unsigned long long(64비트)로는 저장할 수 없습니다.