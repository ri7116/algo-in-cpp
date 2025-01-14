#include<bits/stdc++.h>
using namespace std;
vector<string> v1;
vector<string> v2;
int n;
bool cmp(string a, string b){
    if(a.size()!=b.size()) return a.size()<b.size();
    else return a<b;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end(),cmp);
    int tmp;
    for(int i=0;i<v1.size();i++){
       if(i==0) v2.push_back(v1[i]); 
       if(v2.back() != v1[i]) v2.push_back(v1[i]); 
    }
    for(auto a: v2){
       cout<<a<<endl; 
    }
}

