#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000004];
int indegree[1000004];
int Time[100004];
int result[100004];
priority_queue<int> q;
int ans;
int a,b;
int n,k;


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Time[i]>>k;
		for(int j=0;j<k;j++){
			cin>>a;
			v[a].push_back(i);
			indegree[i]++;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) {
			q.push(-i);
			result[i]=Time[i];
		}
	}
	while(!q.empty()){
		int tmp=-q.top();
		// cout<<tmp<<"방문 했고 ans에 +"<<Time[tmp]<<"현재까지 소요된시간"<<ans<<endl;
		q.pop();
		for(auto t: v[tmp]){
			result[t]=max(result[t],result[tmp]+Time[t]);//중요한 부분
			if(--indegree[t]==0) {
				//이 때 방문인건가?
				q.push(-t);
				// result[t]=max(result[t],result[tmp]+Time[t]); (X)
			}
		}
	}
	cout<<*max_element(result+1,result+1+n);
}
//위상 정렬에서 병렬된 시간을 계산하는 문제(스타크래프트 건물 짓는 시간처럼)
//중간 순서에 상관 없이 결과에 최대값을 넣어야 함