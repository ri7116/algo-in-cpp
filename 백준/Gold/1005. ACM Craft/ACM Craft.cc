#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[1000004];
int dp[1000004];
int target;
vector<int> v[1000004];

int fuc(int a){
    if(a==0) return 0;
    int result = 0;
    if(dp[a]!=-1) return dp[a];//메모제이션
    for(auto k:v[a]){
        result=max(result,fuc(k));
    }
    return dp[a]=result+arr[a];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--){
    
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        arr[i]=0;
        dp[i]=-1;
        v[i].clear();
    }

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i < m;i++){
        int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    cin>>target;
    cout<<fuc(target)<<'\n';
    }
}
//dp+메모제이션 위상정렬이 아니네.. ㅋㅋ top-down 방식
//초기화시 N까지 해야함을 주의
//dp초기화시 -1임을 해야함 why? time>=0이라 전부 0이면 계산을 전부해야 하니까 