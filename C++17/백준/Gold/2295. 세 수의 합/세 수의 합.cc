#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005];
vector <int> two;
int mac;

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            two.push_back(a[i]+a[j]);
        }
    }
    sort(two.begin(),two.end());

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //cout<<i<<" "<<j<<endl;
            if(binary_search(two.begin(),two.end(),a[j]-a[i])){ // !!two = 새로운 합 - l 우리는 합이 최대인 것을 찾는 것임.
                //cout<<a[j]<<" "<<a[i]<<'\n';
                if(a[j]>=mac) mac=a[j];
            }
        }
    }
    cout<< mac;
}