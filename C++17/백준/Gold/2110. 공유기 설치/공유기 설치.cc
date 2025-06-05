#include<bits/stdc++.h>
using namespace std;


unsigned long long n,m;
int arr[300004];
int ans=-1;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int st=1;
	int ed=arr[n-1]-arr[0];
	// cout<<"ed : "<<ed<<'\n';
	while(st<=ed){
		int mid=(st+ed)/2;
		int cnt=1;
		int cur_idx=0;
		for(int i=1;i<n;i++){
			if(arr[i]-arr[cur_idx]>=mid) {
				cnt++;
				cur_idx=i;
			}
		}
		// cout<<"mid : "<<mid<<'\n';

		if(cnt>=m){
			ans=max(ans,mid);
			// ed=mid-1;
			st=mid+1;
		}
		else{
			// st=mid+1;
			ed=mid-1;

		}
	}
	cout<<ans;
}
