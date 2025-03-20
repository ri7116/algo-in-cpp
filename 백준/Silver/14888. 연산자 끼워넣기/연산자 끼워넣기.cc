#include<bits/stdc++.h>
using namespace std;
int n;
int num[100];
int arr[100];
int start[4];
int cnt[4];
int max1=-9876543210;
int min1=9876543210;

void fuc(int depth){
    if(depth==n-1){
        int tmp=num[0];
        for(int i=0;i<n-1;i++){
            if(arr[i]==0)   tmp+=num[i+1];
            if(arr[i]==1)   tmp-=num[i+1];
            if(arr[i]==2)   tmp*=num[i+1];
            if(arr[i]==3)   tmp/=num[i+1];
            
        }
        // for(int i=0;i<n-1;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        if(tmp>max1) max1=tmp;
        if(tmp<min1) min1=tmp;
        //cout<<"1";
        return;
    }
    for(int i=0;i<4;i++){
        if(cnt[i]+1>start[i]) continue;
        cnt[i]++;
        arr[depth]=i;
        fuc(depth+1);
        cnt[i]--;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<4;i++){
        cin>>start[i];
    }
    fuc(0);
    cout<<max1<<endl;
    cout<<min1<<endl;

}
//1. 