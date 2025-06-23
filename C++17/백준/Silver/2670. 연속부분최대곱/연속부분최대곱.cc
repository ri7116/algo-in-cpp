//두번째 풀이 그리디
//현재와 이전을 곱하고 곱한 값이 더 작으면 현재값 그대로 적기 아니면 곱한 값 적기 
#include<bits/stdc++.h>
using namespace std;
int n;
double arr[100004];
double ans[100004];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ans[0]=arr[0];
    for(int i=1;i<n;i++){
        if(ans[i-1]*arr[i]>arr[i]) ans[i]=ans[i-1]*arr[i];
        else ans[i]=arr[i];
    }
    sort(ans,ans+n);
    printf("%.3f",ans[n-1]);
}
