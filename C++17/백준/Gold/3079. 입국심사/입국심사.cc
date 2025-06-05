#include<bits/stdc++.h>
using namespace std;


unsigned long long n,m;
int arr[100004];
unsigned long long ans=20000000000000000000;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	unsigned long long st=1;
	unsigned long long ed=arr[n-1]*m;
	//cout<<"ed : "<<ed<<'\n';
	while(st<=ed){
		unsigned long long mid=(st+ed)/2;
		unsigned long long cnt=0;
		for(int i=0;i<n;i++){
			cnt+=mid/arr[i];
		}
	//	cout<<"mid : "<<mid<<'\n';

		if(cnt>=m){
			ans=min(ans,mid);
			ed=mid-1;
		}
		else{
			st=mid+1;
		}
	}
	cout<<ans;
}
//1. 이분탐색에서 ed의 값 설정도 아주 중요한 문제임
//2. 시간을 기준으로 가판대에서 몇명을 처리할 수 있나요?