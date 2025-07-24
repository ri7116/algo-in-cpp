#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int n,m;
vector<pair<int,int>> adj[100004];
priority_queue<pair<int,int>> q;
int dist[100004];//표
int pre[100004];
int process[100004];
int from,to,w;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>from>>to>>w;
        adj[from].push_back({to,w});
    }
    int st,ed;
    cin>>st>>ed;
    for(int i=1;i<=n;i++){
        dist[i] = INF;
        pre[i] = -1;
    }
    dist[st]=0;
    q.push({0,st}); // {거리, 노드}
    while(!q.empty()){
        int a= q.top().second;
        q.pop();
        if(process[a]) continue; // 이미 처리된 노드면 건너뛰기
        process[a] = 1; // 노드 a를 처리함
        for(auto u: adj[a]){
            int b= u.first;
            int w= u.second;
            if(dist[a]+w <dist[b]){
                dist[b] = dist[a] + w;
                pre[b] = a;
                q.push({-dist[b], b}); // 우선순위 큐에 거리 기준으로 삽입
            }
        }
    }
    cout<<dist[ed]<<"\n";
    vector<int> path;
    for(int i=ed; i!=-1; i=pre[i]){
        path.push_back(i);
    }       
    reverse(path.begin(), path.end());
    cout<<path.size()<<"\n";
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
}
