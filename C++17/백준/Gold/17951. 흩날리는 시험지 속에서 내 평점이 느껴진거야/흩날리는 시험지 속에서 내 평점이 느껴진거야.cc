#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,x,ans,all,mn=21;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
        all += x;
        mn = min(mn,x);
    }

    int l=mn,r=all;
    while (l<=r) {
        int mid = (l+r)/2,sum=0,cnt=0;

        for (int i=0; i<n; i++) {
            sum += v[i];

            if (sum>=mid) {
                cnt++;
                sum = 0;
            }
        }

        if (sum>=mid) {
            cnt++;
        }

        if (cnt>=k) {
            l=mid+1;
            if (cnt==k)
                ans = max(ans,mid);
        }
        else {
            r=mid-1;
        }
    }

    cout << ans;
}

//1. 정렬을 안해도 되는 이분탐색이네~ 색다르다 