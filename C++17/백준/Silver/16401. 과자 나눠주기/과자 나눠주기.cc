#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>

using namespace std;

int snack[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int M, N;

	int start = 1;
	int end = 0;
	int ans = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> snack[i];
	}

	end = *max_element(snack, snack+N);

	while (start <= end)
	{
		int cum_sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			cum_sum += snack[i] / mid;
		}

		if (cum_sum >= M)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	
	if (ans == 0) cout << "0";
	else cout << ans;
}
