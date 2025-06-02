#include<bits/stdc++.h>
using namespace std;
long long  n,m;
long long stone[400000];
long long ans=2100000000;
int main(){
    cin>>n>>m;
    for(long long i=0;i<m;i++){
        cin>>stone[i];
    }

    long long st=1;
    long long ed=1000000001;

    while(st<=ed){
        long long mid=(st+ed)/2;
        long long cnt=0;
        for(long long i=0;i<m;i++){
            cnt+=stone[i]/mid;
            if(stone[i]%mid)cnt++;
        }   


        if(cnt<=n){
            ans=min(ans,mid);
            ed=mid-1;
        }
        else st=mid+1;
    }
    cout<<ans;
}
