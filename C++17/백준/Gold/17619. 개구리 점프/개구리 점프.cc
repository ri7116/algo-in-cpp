

#include<bits/stdc++.h>
using namespace std;

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
	return true;
}

struct st{
    int a;
    int b;
    int c;

    bool operator<(const st other){
        if(a==other.a) return b<other.b;
        else return a<other.a;
    } 
};

//유니온 파인드 나중에

st arr[1000004];
int n,q;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i]={a,b,i+1};//x1,x2 선분번호
    }
    sort(arr,arr+n);

    int cur=arr[0].c;//대표선분 즉 부모
    int R=arr[0].b;
    for(int i=1;i<n;i++){
        //x1이 x2 왼쪽에 있으면(겹치면)
        if(arr[i].a<=R) uni(cur,arr[i].c), R=max(R, arr[i].b);
        //안겹치면 처리
        else cur=arr[i].c, R=arr[i].b;
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        //파인드
        int A=find(a);
        int B=find(b);
        if(A==B) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}
// 1. 커스텀 정렬
// 2. x좌표만 비교하면됨 
// 참고
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int arr[100001];

// int findf(int x) {
// 	if (x == arr[x]) return x;
// 	return arr[x] = findf(arr[x]);
// }

// int N, Q;
// pair<pair<int, int>, int> logs[100000];

// int cur = -1, R = -1;

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	cin >> N >> Q;
// 	for (int i = 1; i <= N; i++) arr[i] = i;

// 	for (int i = 0; i < N; i++) {
// 		cin >> logs[i].first.first >> logs[i].first.second >> logs[i].second; //x1, x2, y
// 		logs[i].second = i + 1;//y => 선분번호?
// 	}

// 	sort(logs, logs + N);

// 	for (int i = 0; i < N; i++) {
// 		if (R < logs[i].first.first) cur = logs[i].second, R = logs[i].first.second;//겹치지 않으면) cur이 y인데 필요하나?
// 		else R = max(R, logs[i].first.second), arr[logs[i].second] = cur;//겹치면)x2 좌표가 더 큰게 오른쪽이고 arr[선분번호] = cur이 코드는 모르겠네?
// 	}

// 	while (Q--) {
// 		int x, y; cin >> x >> y;
// 		cout << (findf(x) == findf(y)) << '\n';//x랑 y가 같은 집합이니?
// 	}
// }