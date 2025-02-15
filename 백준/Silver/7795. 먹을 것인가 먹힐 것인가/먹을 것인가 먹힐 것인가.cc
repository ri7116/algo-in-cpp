#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int main(){
    cin>>k;
    
    while(k--){
    cin>>n>>m;
    vector <int> v1;
    vector <int> v2;
    v1.clear();//넣어야됨?
    v2.clear();//넣어야됨?
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        v2.push_back(a);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ans=0;;
    for(int i=0;i<v1.size();i++){
        for(int j=v2.size()-1;j>=0;j--){
            if(v2[j]<v1[i]) {
                ans+=j+1;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    }
}
//시간 복잡도 계산을 어떻게? nlogn인가? 브루트포스 쓰면 4억으로 4초 걸림
//개행문자 안 넣어서 틀림