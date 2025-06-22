#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100004];
ll n,m;
ll ret;
ll ans;
ll check(ll Time){//time 변수명 가능한지 아닌지 나중에 찾아봐야 됨
	ll cnt=m;//!초기에 m명이 탐
	for(int i=1;i<=m;i++){
		cnt+=Time/arr[i];
	}
	return cnt>=n;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>arr[i];
	}
	ll st=1;
	ll ed=1e15;
	ll mid;
	if(n<=m){
		cout<<n;
		return 0;
	}
	while(st<=ed){
		mid=(st+ed)/2;
		//인원수가 충분히 가능하다면 시간을 줄여보자
		if(check(mid)){
			ed=mid-1;
			ret=mid;
		}
		else st=mid+1;
	}
	//cout<<ret<<endl;
	//cout<<ret/arr[1]<<endl;
	//cout<<ret/arr[2]<<endl;
	//ret은 충분히 줄 수 있을때 mid는 충분히 줄 수 없을때 이 부분이 분기점이다.
	//뒤부터 나머지가 0 

	//잘못 푼 풀이
	// for(int i=m;i>=1;i--){
	// 	if(ret%arr[i]==0){
	// 		//cout<<ret<<endl;
	// 		//cout<<ret/arr[i]<<endl;
	// 		//cout<<(ret-1)/arr[i]<<endl;
	// 		cout<<i;
	// 		return 0;
	// 	}
	// }


	//1. ret-1초까지 탄 사람의 수 
	ll cnt = m;  // 0초에 m명 탑승
	for (int i = 1; i <= m; i++) {
		cnt += (ret - 1) / arr[i];  // ret 이전까지 탄 사람 수
	}

	// 2. ret초에 탈 수 있는 기구 중 n번째 아이가 타는 기구를 찾는다
	for (int i = 1; i <= m; i++) {
		if (ret % arr[i] == 0) {
			cnt++;  // 한 명이 더 탐
			if (cnt == n) {
				cout << i;
				return 0;
			}
		}
	}
}
//1. 가장 마지막에 타는건 뒤부터 ret을 arr[i]로 나눴을때 나머지가 0 첫 번째로 나오는 수
//2. 처음에 m개 만큼 아이들이 놀이기구를 탄다.