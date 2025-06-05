#include<bits/stdc++.h>
using namespace std;

int ans=1;
long long n;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	while(1){
		if(n>ans){
			n-=ans;
			ans++;
		}
		else if(n==ans){
			ans++;
			break;
		}
		else{
			break;
		}
	}
	cout<<ans-1;
}
//1. 그리디