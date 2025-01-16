#include<bits/stdc++.h>
using namespace std;
set<int> s;
int n,m;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a){
            s.insert(i);
        }
    }
    // for(int i=1;i<=n;i++){
    //     if(s.find(i)!=s.end()) cout<<1<<" ";
    //     else cout<<0<<" ";
    // }
    // cout<<endl;
    int cur=1;
    for(int i=0;i<m;i++){
        int what;
        cin>>what;
        if(what==1){
            int a;
            cin>>a;
            if(s.find(a)!=s.end()) s.erase(a);//존재한다면
            else s.insert(a);
            // for(int i=1;i<=n;i++){
            //     if(s.find(i)!=s.end()) cout<<1<<" ";
            //     else cout<<0<<" ";
            // }
            // cout<<endl;
        }
        if(what==2){
            int a;
            cin>>a;
            //cur=(cur+a)%n;
            //if(cur==0) cur=n;//나머지가 0일때 처리
            cur = (cur + a - 1) % n + 1;
        }
        if(what==3){
            if (s.empty()) cout << -1 << '\n';
//            cout<<cur<<" 어퍼바운드 : "<<*s.upper_bound(cur)<<'\n';//여기 확인해보자
            else{
            auto it = s.lower_bound(cur);
            if (it != s.end()) cout << *it - cur << '\n';
            else cout << n - cur + *s.begin() << '\n';
            }
        }
    }
}

//*s.begin() s.lower_bound()