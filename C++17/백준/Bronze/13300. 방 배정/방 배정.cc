#include<bits/stdc++.h>
using namespace std;
int a,b;
int l,m;
int arr[1004][1004];
int cnt;


int main(){
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>l>>m;
        arr[l][m]++;
    }
    for(int i=1;i<=6;i++){
        for(int j=0;j<2;j++){
            cnt+=arr[j][i]/b;// 몫 더하고
            if(arr[j][i]%b!=0) cnt++;// 나누어 떨어지지 않는다면 ++
        }
    }
    cout<<cnt;
}