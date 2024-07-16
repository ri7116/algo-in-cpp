#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2250010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n * n); //2차원 배열은 sort를 못함
    cout << arr[n * n - n] << endl;
    return 0;
}