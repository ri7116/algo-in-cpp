//1. .4f
//2. long long은 int임
#include<bits/stdc++.h>
using namespace std;
int n;
double arr[100004];
double ans=-1;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans=max(ans,arr[i]);
    }
    for(int i=0;i<n-1;i++){
        double tmp=arr[i];
        for(int j=i+1;j<n;j++){
            tmp*=arr[j];
            ans=max(ans,tmp);
        }
    }
    printf("%.3f\n", ans);
}
