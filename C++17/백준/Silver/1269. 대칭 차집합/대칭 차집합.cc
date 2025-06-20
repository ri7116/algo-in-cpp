#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> s1;
set<int> s2;
int a;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;	
		s1.insert(a);
	}
	for(int i=0;i<m;i++){
		cin>>a;	
		s2.insert(a);
	}
	int cnt=0;
	for( auto a:s1){
		if(s2.find(a)!=s2.end()) cnt++;
	}
	int ans=0;
	ans=ans+s1.size()-cnt;
	ans=ans+s2.size()-cnt;
	cout<<ans;
	
}
//1. auto set은 하나씩 접근가능
//2. cout<<s1[1];은 불가능