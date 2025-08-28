#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int a,b;
int cnt[1000004];

vector<int> p(1000004,-1);

int find(int x){
	if(p[x]<0) return x;
	return p[x] = find(p[x]);

}

bool uni(int u, int v){
	u=find(u);
	v=find(v);
	
	if(u==v) return false;
		
	if(p[v] < p[u]) swap(u, v);// u가 v보다 트리의 높이가 더 큼을 보장(흡수 해도 높이가 바뀌지 않음)
	if(p[u] == p[v]) p[u]--; //같은 랭크(트리의 높이)에 대한 처리
	
	p[v]=u;
    cnt[u]+=cnt[v];//**  이 코드 추가
	return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<=1000004;i++){
        cnt[i]=1;//**  이 코드 추가
    }
    for(int i=0;i<n;i++){
        cin>>str;
        if(str == "I" ){
            cin>>a>>b;
            uni(a,b);
        }
        else{
            cin>>a;
            cout<<cnt[find(a)]<<'\n';
        }
    }
}
// 유니온 파인드에서 노드 개수를 찾는 문제