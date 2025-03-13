#include<bits/stdc++.h>
using namespace std;
string str;
//vector <int> v[20004];
int visited[20004];
int n, k;
int ans;
int main(){
    cin>>n>>k;
    cin>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='H') {
            int min_=-999;
            int max_=-999;
            if(i-k<0) min_=0;  
            else min_=i-k;

            if(i+k>=n) max_=n-1;  
            else max_=i+k;

            for(int j=min_;j<=max_;j++){
                if(str[j]=='P' and !visited[j]) {
                    ans++;
                    visited[j]=1;
                    //cout<<i<<"번째 햄버거 "<<j<<"번째 사람이 먹었습니다 \n";
                    break;
                }
            }
        }
    }
    cout<<ans;
}