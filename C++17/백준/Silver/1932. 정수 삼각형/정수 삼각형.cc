#include<iostream>
#include<algorithm>
using namespace std;

int a[504][504];
int D[504][504];
int k;
int main() {
	cin >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= i; j++) {
			cin>>a[i][j];
		}
	}
	D[1][1] = a[1][1];
	D[2][1] = a[1][1]+a[2][1];
	D[2][2] = a[1][1]+a[2][2];
	for (int i = 3; i <= k; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {//맨 왼쪽
				D[i][j] = D[i - 1][j] + a[i][j];
			}

			else if (j == i) {//맨 오른쪽
				D[i][j] = D[i - 1][j-1] + a[i][j];
			}

			else {
				D[i][j] =max(D[i - 1][j], D[i - 1][j - 1]) + a[i][j];
			}
		}
	}

	int mac=0;
	for (int i = 1; i <= k; i++) {
		if (D[k][i] >= mac) mac = D[k][i];
	}
	cout << mac;
	
}
