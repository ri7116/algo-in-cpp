#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;
int n, m, a[54][54], result = 987654321;
vector<vector<int>>chickenList;
vector <pair<int, int>> home, chicken;

void combi(int start, vector <int> v) {
	if (v.size() == m) { //기저사례 m번 뽑혔다 
		chickenList.push_back(v);
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}

	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) home.push_back(make_pair(i, j));
			if (a[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	vector<int> v;
	combi(-1, v);
	for (vector<int> clist : chickenList) {
		int ret = 0;
		for (pair<int, int> kome : home) {
			int _min = 9999999;
			for (int ch : clist) {
				int _dist = abs(kome.first - chicken[ch].first) + abs(kome.second - chicken[ch].second);
				_min = min(_min, _dist);

			}
			ret += _min;
		}
		result = min(result, ret);
	}
	cout << result;
}
