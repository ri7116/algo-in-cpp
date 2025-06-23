#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1004];
int lis[1004];
pair<int,int> ans[1004];
int INF=-1;
stack<int> stk;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    fill(lis,lis+n,INF);
    int leng=0;
    for(int i=0;i<n;i++){
        auto pos=lower_bound(lis,lis+leng,arr[i]);
        if(*pos==INF) {
            leng++;
        }
        int idx=pos-lis;//0 index
        lis[idx]=arr[i];
        ans[i].first=idx;//index 저장
        ans[i].second=arr[i];
    }
    
    cout<<leng<<'\n';
    for(int i=n-1;i>=0;i--){
        if(leng-1==ans[i].first){
            // cout<<ans[i].second<<" ";
            stk.push(ans[i].second);
            leng--;
        }
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}