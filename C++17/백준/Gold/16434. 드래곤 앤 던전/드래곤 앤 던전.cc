#include<bits/stdc++.h>
using namespace std;

long long atk;
long long n;
long long arr[1000000][3];
long long ans=1e18;// long long일땐 max값을 어떻게 설정할까?
// 1 공격력 생명력
// 2 공격력증가 생명력회복

int play(long long max_hp){
	long long cur_hp=max_hp;
	long long cur_atk=atk;
	for(int i=0;i<n;i++){
		
		if(arr[i][0]==1){//고블린 방
			//주인공 공격은 n번 고블린 공격은 n-1번
			//주인공 공격 횟수
			long long patrin_cnt=arr[i][2]/cur_atk;
			if(arr[i][2]%cur_atk!=0) patrin_cnt++;
			//고블린 공격 횟수
			long long goblin_cnt=patrin_cnt-1;
			cur_hp-=goblin_cnt*arr[i][1];
			if(cur_hp<=0) return 0; 	
		}
		else{// 회복의 방
			cur_atk+=arr[i][1];
			cur_hp+=arr[i][2];
			if(cur_hp>max_hp) cur_hp=max_hp;
		}
	}
	return 1;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>atk;
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}

	long long st=1;
	long long ed=1e18;
	long long mid;

	while(st<=ed){
		mid=(st+ed)/2;

		if(play(mid)){
			ed=mid-1;
			ans=min(mid,ans);
		}
		else{
			st=mid+1;
		}
	}
	cout<<ans;
}
//1. 공격력 체력 훼손 ㄴㄴ
//2. ed를 아주 크게 해야됨
//3. 고블린 공격을 시뮬레이션으로 구현하면 atk가 1일때 계산이 많아져 틀리게 됨
