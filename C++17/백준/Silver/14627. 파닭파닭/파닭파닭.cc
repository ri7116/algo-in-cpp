#include<bits/stdc++.h>
using namespace std;

long long t;
long long arr[1000004];
long long arr2[1000004];
long long n,m, mx;
long long ans=1e18;
long long check(long long target){
	if(target>mx) return 0;
	long long cnt=0;
	for(long long i=0;i<n;i++){
		cnt+=(arr[i]/target);
	}

	return cnt;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;//파 닭
	long long Sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		Sum+=arr[i];
		mx=max(arr[i],mx);
	}

	long long st=1;
	long long ed=1e18;
	long long mid;
	while(st<=ed){
		mid=(st+ed)/2;

		if(check(mid)>=m){
			st=mid+1;
//			ans=min(ans,Sum-mid*check(mid));
			ans=min(ans,Sum-mid*m);
		}
		else{
			ed=mid-1;
		}
	}
	cout<<ans;
}