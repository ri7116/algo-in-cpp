#include <iostream>
#include <vector>

using namespace std;

int n, l, answer=0;

void checkRoad(int row, vector<vector<int> >& board) {
	int prev = board[row][0];
	vector<bool> slope(n, false);
	for (int col=1; col<n; col++) {
		if (abs(prev - board[row][col]) > 1) return ;// 1보다 크면

		if (prev < board[row][col]) {// 오르막 길 일때
			for (int i=col-l; i<col; i++) {
				if (i < 0 || slope[i]) return ;// 이미 경사로를 놓았다면 길이아님
				slope[i] = true;
			}
		} else if (prev > board[row][col]) {// 내리막 길 일때
			for (int i=col; i<col+l; i++) {
				if (i >= n || slope[i]) return ;//이미 경사로를 놓았다면 길이아님
				slope[i] = true;
			}
		}
		prev = board[row][col];
	}
	answer++;
}

int main() {
	cin >> n >> l;
	vector<vector<int> > board(n, vector<int>(n)), board_rotated(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
			board_rotated[j][i] = board[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		checkRoad(i, board);// 행
		checkRoad(i, board_rotated);// 열
	}
	cout << answer << "\n";
}