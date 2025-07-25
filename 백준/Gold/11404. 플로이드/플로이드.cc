#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n,m;
int ans[104][104];
vector<pair<int,int>> adj[104];
int main(){
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j] = INF;
            if(i==j) ans[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int from,to,w;
        cin>>from>>to>>w;
        //adj[from].push_back({to,w});
        ans[from][to]=min(ans[from][to],w);    
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]>ans[i][k]+ans[k][j]){
                    ans[i][j]= ans[i][k]+ans[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j] == INF) {
                cout<<0<<" ";
                continue;
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}