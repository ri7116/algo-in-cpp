#include<bits/stdc++.h>
using namespace std;
int ans;
int k;
int main(){
    cin>>k;
    while(k--){
        int a,b;
        ans=1;
        cin>>a>>b;
        int ja=1;
        int mo=b;
        for(int i=0;i<a;i++){
            ans*=mo--;
            ans/=ja++;
        }
        cout<<ans<<'\n';
    }
}
