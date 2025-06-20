#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v1;
vector<int> v2;
int a;

int check(int target){
	int st=0;
	int ed=m-1;
	int mid;
	while(st<=ed){
		mid=(st+ed)/2;

		if(v2[mid]==target) return 1;
		else if(v2[mid]<target) st=mid+1;
		else ed=mid-1; //(v2[mid]<target)
	}
	return 0;
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;	
		v1.push_back(a);
	}
	for(int i=0;i<m;i++){
		cin>>a;
		v2.push_back(a);
	}
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	int ans=0;
	int cnt=0;
	for(auto k: v1){
		if(check(k)) cnt++;
	}
	ans+=v1.size()-cnt;
	ans+=v2.size()-cnt;

	cout<<ans;
	
}
//이분 탐색을 이용한 풀이, set을 이용한 풀이 두 가지가 존재함