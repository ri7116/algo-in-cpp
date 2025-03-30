#include<bits/stdc++.h>
using namespace std;
long long arr[10004];
int a,b,c;
long long min_=9876543210;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        long long sum=arr[i];
            int st=i+1;
            int ed=n-1;
            while(i<st and st<ed){
                sum+=arr[st];
                sum+=arr[ed];
                //cout<<i<<" "<<st<<" "<<ed<<endl;
                if(sum>0){
                    if(abs(sum)<abs(min_)){
                        min_=abs(sum);
                        a=i;
                        b=st;
                        c=ed;
                    }
                    sum-=arr[st];
                    sum-=arr[ed];
                    ed--;
                }
                else if(sum<0){
                    if(abs(sum)<abs(min_)){
                        min_=abs(sum);
                        a=i;
                        b=st;
                        c=ed;
                    }
                    sum-=arr[st];
                    sum-=arr[ed];
                    st++;
                }
                else if(sum==0){
                    cout<<arr[i]<<" "<<arr[st]<<" "<<arr[ed]<<endl;
                    return 0;
                }
          }
        
    }
    cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c];
}
//1. if elseif else 조건 잘 넣자