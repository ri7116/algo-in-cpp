#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<pair<int,int>> v2;
vector<pair<int,int>> v3;
int n;
int tmp;
int cnt;
map<int,int> order;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return order[a.second]<order[b.second];
    return a.first>b.first;
}

int main(){
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        if(order[a]==0) order[a]=i+1;
    }

    sort(v.begin(),v.end());
    // cout<<"a :";
    // for(auto a: v){
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    tmp=v[0];
    cnt++;
    for(int i=1;i<v.size();i++){
        if(v[i]!=tmp) {
            v2.push_back({cnt,tmp});
            tmp=v[i];
            cnt=1;
        }
        else{
            cnt++;
        }
        if(i==v.size()-1) v2.push_back({cnt,tmp});//마지막이면 그냥 집어넣어
    }
    sort(v2.begin(),v2.end(),cmp);
    for(auto a: v2){
        for(int i=0;i<=a.first-1;i++){
        cout<<a.second<<" ";
        }
    }
}

//빈도를 확인하는 것은!! => map을 활용