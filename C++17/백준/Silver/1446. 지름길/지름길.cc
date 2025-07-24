//(V + E)log(V)
#include<bits/stdc++.h>
using namespace std;
int n, direct;
int from,to,dist;
int dp[1000004];
int dis[1000004];

vector<pair<int,int>> v[100004];
int main(){
    cin>>n>>direct;
    for(int i=0;i<n;i++){
        cin>>from>>to>>dist;
        v[to].push_back({from,dist});    
    }

    dis[0]=0;
    for(int i=1;i<=direct;i++){
        dis[i]=dis[i-1]+1;
        for(auto a: v[i]){
            dis[i]=min(dis[i],dis[a.first]+a.second);
        }
    }
    cout<<dis[direct];
}