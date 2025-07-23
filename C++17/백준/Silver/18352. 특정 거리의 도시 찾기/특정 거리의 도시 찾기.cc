//(V + E)log(V)
#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
priority_queue<pair<int,int>> q;

int n,m,k,x;//도시, 도로, 거리정보, 출발 도시 번호
int dis[1000004];//[목적지]까지의 최단 거리 비용 상태
int process[1000004];//노드 처리 상태
vector<pair<int,int>> adj[1000004]; //adj[시작점]= {목적지, 가중치} 간선인가?



int main(){
    cin>>n>>m>>k>>x;
    for(int i=0;i<m;i++){
        int aa,bb;
        cin>>aa>>bb;
        adj[aa].push_back({bb,1}); // {목적지, 가중치} 순서로 수정
    }


    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }

    dis[x]=0;
    q.push({0, x}); // 시작점을 큐에 추가

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
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(dis[i]==k) v.push_back(i);
    }

    if(v.size()==0) cout<<-1;
    else {
        sort(v.begin(), v.end()); // 결과를 오름차순으로 정렬
        for(auto a:v){
            cout<<a<<"\n";
        }
    };
}