#include<bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long st=1;
    long long ed=10000000000000;
    long long ans=20000000000000;
    while(st<=ed){
        long long mid=(st+ed)/2;
        
        long long cnt=0;
        for(int i=0;i<times.size();i++){
            cnt+=mid/times[i];
        }
        
        if(cnt>=n){
            ans=min(ans,mid);
            ed=mid-1;
        }
        
        else{
            st=mid+1;
        }
    }
    return ans;
}