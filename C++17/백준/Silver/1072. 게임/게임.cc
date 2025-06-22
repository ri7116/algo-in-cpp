#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100004];
ll n,m;
ll res=-1;
ll ans;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	ll z=m*100/n;
	ll st=1;
	ll ed=1000000004;
	ll mid;

	while(st<=ed){
		mid=(st+ed)/2;
	
		if( ( ( (m+mid) * 100 ) / ( n+mid ) ) != z){
			res=mid;
			ed=mid-1;
		}
		else{
			st=mid+1;
		}
	}
	cout<<res;
}
//1. *100을 나중에 하면 0*100이 되어서 0이 됩니다.