#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000004];
int indegree[1000004];
priority_queue<int> q;
vector<int> ans;
int a,b;
int n,k;


int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>a>>b;
		v[a].push_back(b);
		indegree[b]++;
	}
	
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) q.push(-i);
	}
	while(!q.empty()){
		int tmp=-q.top();
		q.pop();
		ans.push_back(tmp);
		for(auto t: v[tmp]){
			if(--indegree[t]==0) q.push(-t);
		}
	}
	for(auto t: ans){
		cout<<t<<" ";
	}
}
//위상 정렬에서 같은 층에서 순서를 정의 하는 문제