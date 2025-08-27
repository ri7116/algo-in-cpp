#include<bits/stdc++.h>
using namespace std;

// struct st{
//     int a,
//     int b,
// };

// vector<st> v;
vector<pair<int,int>> v;
int n,k;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    while(n--){
        int ans=0;
        cin>>k;
        v.clear();
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        // dp 느낌 n^2을 n으로 해결
        ans++;
        int Max=v[0].second;
        for(int i=1;i<k;i++){
            if(v[i].second<Max){
                ans++;
                Max=v[i].second;
            }
        }
        cout<<ans<<endl;
    }
}