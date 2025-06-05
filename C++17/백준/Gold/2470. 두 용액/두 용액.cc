#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100004];


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	int ans=2000000000;
	sort(arr,arr+n);
	int st=0;
	int ed=n-1;
	int ans_a;
	int ans_b;
	while(st<ed){
		if(ans>abs(arr[ed]+arr[st])){
			ans_a=st;
			ans_b=ed;
			ans= min(abs(arr[ed]+arr[st]),ans);
		}

		if(arr[ed]+arr[st]<=0) st++;
		else ed--;
	}
	cout<<arr[ans_a]<<" "<<arr[ans_b]<<endl;
}
//abs는 unsigned long long 처리 못함