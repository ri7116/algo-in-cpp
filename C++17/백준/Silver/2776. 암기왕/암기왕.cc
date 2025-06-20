#include<bits/stdc++.h>
using namespace std;

int t;
int arr[1000004];
int arr2[1000004];
int n,m;

int check(int target){
	long long st=0;
	long long ed=n-1;
	long long mid;
	while(st<=ed){
		mid=(st+ed)/2;
		if(target==arr[mid]) return 1;
		else if(target>arr[mid]) st=mid+1;
		else ed=mid-1;
	}
	return 0;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		
		sort(arr,arr+n);

		int a;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>a;
			cout<<check(a)<<'\n';
		}
	}
}