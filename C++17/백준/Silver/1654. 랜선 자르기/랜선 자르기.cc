#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[1000004];
long long ans;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    long long st=1;
    long long ed=arr[n-1];
    long long md;
        
    while(st<=ed){
        md=(st+ed)/2;
        int cnt=0;  

        for(int i=0;i<n;i++){   
            cnt+=arr[i]/md; 
        }   
        if(cnt>=m){ 
            st=md+1;    
            ans = max(ans,md); //가능할때 가능한 큰 정답을 넣자 md값이 불만족할때 while문을 통과해서 끝날 수 있기 때문에
        }
        else{
            ed=md-1;
        }
    }
    cout<<ans;
}