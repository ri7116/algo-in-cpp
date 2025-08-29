#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<long long,long long>> v;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        if(b<a){
            v.push_back({b,a});            
        }
    }
    sort(v.begin(),v.end());

    long long ans=m;
    if(v.size()>=1){
    long long st=v[0].first;
    long long ed=v[0].second;
    for(int i=1;i<v.size();i++){
        //겹칠 때(완전히 포함 할 때랑, 끝이 더 길때의 경우를 둘 다 고려함)
        if(v[i].first<ed){
            ed=max(ed,v[i].second);
        }
        //안 겹칠 때 else if로 하면 0인 경우를 깔끔하게 처리함
        else {
            ans += (ed - st) * 2; // 이전까지 합쳐진 구간의 길이를 정산
            st = v[i].first;      // 새 구간으로 st, ed를 모두 갱신
            ed = v[i].second;
        }
    }
    ans+=(ed-st)*2;
    }
    cout<<ans;
}