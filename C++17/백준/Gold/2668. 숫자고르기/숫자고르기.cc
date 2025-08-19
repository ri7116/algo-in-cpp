#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int N;
int arr[101];
bool visited[101];

void DFS(int start, int cur)
{

	if (visited[cur])
	{
		if (start == cur)	v.push_back(arr[start]);

		return;
	}
	visited[cur] = true;
	DFS(start, arr[cur]);
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <=N; i++) {
		memset(visited, false, sizeof(visited));
		DFS(i, i);
	}
	
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout<<v[i] << "\n";
}
//방향그래프에서 자기 자신에서 DFS 시전 했을 때 자기 자신으로 돌아오면(사이클이 존재하면 ) 벡터에 넣기 