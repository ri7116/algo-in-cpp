//(V + E)log(V)
#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int tmp_a, tmp_b;
int n,m;//도시, 도로
int dis[1000004];//[목적지]까지의 최단 거리 비용 상태
int dis_A[100004];
int dis_B[100004];
int process[1000004];//노드 처리 상태
vector<pair<int,int>> adj[1000004]; //adj[시작점]= {목적지, 가중치} 

int main(){
    cin>>n>>m;// 정점 간선
    for(int i=0;i<m;i++){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        adj[aa].push_back({bb,cc}); // {목적지, 가중치} 
        adj[bb].push_back({aa,cc}); // 무방향 그래프이므로 양방향 추가
    }
    cin>>tmp_a>>tmp_b;

    // 1번에서 모든 정점까지의 최단거리
    for(int i=1;i<=n;i++){
        dis[i]=INF;
        process[i]=0;
    }
    
    dis[1]=0;
    priority_queue<pair<int,int>> q;
    q.push({0, 1}); // {가중치,목적지} 시작점을 큐에 추가

    while(!q.empty()){
        int a= q.top().second;
        q.pop();
        if(process[a]) continue;
        process[a]=1;
        for(auto u: adj[a]){
            int b=u.first;
            int w=u.second;
            if(dis[a]+w<dis[b]){
                dis[b]=dis[a]+w;
                q.push({-dis[b], b});
            }
        }
    }

    // tmp_a에서 모든 정점까지의 최단거리
    for(int i=1;i<=n;i++){
        dis_A[i]=INF;
        process[i]=0;
    }
    
    dis_A[tmp_a]=0;
    q.push({0, tmp_a});
    
    while(!q.empty()){
        int a= q.top().second;
        q.pop();
        if(process[a]) continue;
        process[a]=1;
        for(auto u: adj[a]){
            int b=u.first;
            int w=u.second;
            if(dis_A[a]+w<dis_A[b]){
                dis_A[b]=dis_A[a]+w;
                q.push({-dis_A[b], b});
            }
        }
    }

    // tmp_b에서 모든 정점까지의 최단거리
    for(int i=1;i<=n;i++){
        dis_B[i]=INF;
        process[i]=0;
    }
    
    dis_B[tmp_b]=0;
    q.push({0, tmp_b});

    while(!q.empty()){
        int a= q.top().second;
        q.pop();
        if(process[a]) continue;
        process[a]=1;
        for(auto u: adj[a]){
            int b=u.first;
            int w=u.second;
            if(dis_B[a]+w<dis_B[b]){
                dis_B[b]=dis_B[a]+w;
                q.push({-dis_B[b], b});
            }
        }
    }
    
    // 1 -> tmp_a -> tmp_b -> n 또는 1 -> tmp_b -> tmp_a -> n
    long long ans1 = (long long)dis[tmp_a] + dis_A[tmp_b] + dis_B[n];
    long long ans2 = (long long)dis[tmp_b] + dis_B[tmp_a] + dis_A[n];
    long long ans = min(ans1, ans2);
    
    if(ans >= INF) cout << -1;
    else cout << ans;
    
    return 0;
}

//1. 무방향
//2. 그래프만 3개면 된다
//3. 다익스트라 3번 돌리기 