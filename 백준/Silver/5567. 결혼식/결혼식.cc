#include<bits/stdc++.h>
using namespace std;
int visited[1000];
vector<int> node[1000];
set<int> ans;

void dfs3(int cur){
    visited[cur]=1;
    //cout<<cur<<"을 넣겠습니다!!!"<<endl;
    ans.insert(cur);
}

void dfs2(int cur){
    visited[cur]=1;
    //cout<<cur<<"을 넣겠습니다!!"<<endl;
    ans.insert(cur);

    for(auto next: node[cur]){
        dfs3(next);
    }
}

void dfs(int cur){
    visited[cur]=1;
    //cout<<cur<<"을 넣겠습니다!"<<endl;
    ans.insert(cur);

    for(auto next: node[cur]){
        dfs2(next);
    }
}
int main(){
    int n;
    int k;
    cin>>k;
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    dfs(1);
    
    cout<<ans.size()-1;
}