#include<bits/stdc++.h>
using namespace std;
int visited[1000];
int ans[1000][10000];
vector<int> node[1000];
void dfs(int cur, int start){
    visited[cur]=1;
    ans[start][cur]=1;

    for(auto next: node[cur]){
        if(visited[next]) continue;
        dfs(next,start);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(a) node[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        for(auto next:node[i]){
            dfs(next,i);
        }
        for(int j=0;j<1000;j++) visited[j]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
}
//dfs문제 였음 결국