#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string str=to_string(i);
        for(int j=0;j<str.size();j++){
            if(str[j]=='3' or str[j]=='6' or str[j]=='9') ans++;
        }
    }
    cout<<ans;
}
//1. to_string 함수가 헷갈렸음