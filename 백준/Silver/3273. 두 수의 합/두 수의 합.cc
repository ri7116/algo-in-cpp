#include<bits/stdc++.h>
using namespace std;
int n,t, ans, cnt;
int num[2000004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        num[t]=1;// 수열에 수 입력받기
    }
    cin>>ans;
    for(int i=1;i<(ans+1)/2;i++){
        if(num[i]==1 and num[ans-i]==1) cnt++;
    }
    cout<<cnt;
}