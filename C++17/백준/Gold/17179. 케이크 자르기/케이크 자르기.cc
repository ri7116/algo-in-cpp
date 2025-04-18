#include <iostream>
#include <algorithm>
using namespace std;
int N, M, L;
int* arr;
int targetCuttingCount;
int answer;

void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		int stl = 0;
		for (int i = 1; i < M+2; i++)
		{
			if (arr[i] - stl >= mid)
			{
				cnt++;
				stl = arr[i];
			}
		}
		if (cnt > targetCuttingCount)
		{
			left = mid + 1;
			answer = max(answer, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> L;
	arr = new int[M+2];
	arr[0] = 0;
	for (int i = 1; i < M+1; i++)
	{
		cin >> arr[i];
	}
	arr[M + 1] = L;
	for (int i = 0; i < N; i++)
	{
		cin >> targetCuttingCount;
		binarySearch(1, L);
		cout << answer << "\n";
		answer = 0;
	}
	return 0;
}
//1. 이분탐색(파라메트릭 서치)
//2. 우리가 찾는건 적절한 mid임!! 답은 mid!!
//3. 가장 작은 조각의 길이의 최대 최소!!! 최대면 같을때 범위를 늘리기 최소면 범위를 줄이기!