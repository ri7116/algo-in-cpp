#include<bits/stdc++.h>
using namespace std;


int n;
int a[10005];
int d1[10005];
int d2[10005];

vector<int> adj[10005];

void dfs(int cur, int par){
    d1[cur]=a[cur];
    d2[cur]=0;
    for(int nxt: adj[cur]){
        if(par==nxt)   continue; // 부모 노드로 가는 경우는 제외
        dfs(nxt,cur);
        d1[cur]+=d2[nxt];
        d2[cur]+=max(d2[nxt],d1[nxt]);
    }
}


int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0); // 1번 노드를 루트로 설정
    cout<<max(d1[1],d2[1])<<"\n"; // 루트 노드에서의 최대값 출력
}

//top down 트리에서의 DP
//어차피 모든 노드를 한번씩 방문하므로 visited 배열은 필요 없음(메모제이션이 알아서 되는 거임)
//바킹독 dp심화 강의 영상에 해설있음