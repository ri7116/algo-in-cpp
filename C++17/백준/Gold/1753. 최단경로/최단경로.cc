//(V + E)log(V)
#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
priority_queue<pair<int,int>> q;// {가중치, 목적지}

int n,m,x,dt;//도시, 도로, 출발지, 도착지
int dis[1000004];//[목적지]까지의 최단 거리 비용 상태
int process[1000004];//노드 처리 상태
vector<pair<int,int>> adj[1000004]; //adj[시작점]= {목적지, 가중치} 



int main(){
    cin>>n>>m;// 정점 간선
    cin>>x;//시작정점
    for(int i=0;i<m;i++){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        adj[aa].push_back({bb,cc}); // {목적지, 가중치} 순서로 수정
    }
    cin>>x>>dt;

    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }

    dis[x]=0;
    q.push({0, x}); // {가중치,목적지} 시작점을 큐에 추가

    while(!q.empty()){
        int a= q.top().second;//경로 비용이 가장 작은 걸 고른다(방문하지 않은 노드 중에 가장 경로 비용이 작은 걸 고른다)
        q.pop();
        if(process[a]) continue;//방문한 노드는 무시한다(방문하지 않은 노드 중에 가장 경로 비용이 작은 걸 고른다)
        process[a]=1; // 해당 노드는 처리 되었다.
        for(auto u: adj[a]){
            int b=u.first;
            int w=u.second;
            if(dis[a]+w<dis[b]){
                dis[b]=dis[a]+w;//시작점에서 b까지의 최단거리 갱신
                q.push({-dis[b], b});// 시작점에서 b까지의 최단거리, b 노드
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dis[i]==INF) cout<<"INF\n";
        else cout<<dis[i]<<'\n';
    }
}