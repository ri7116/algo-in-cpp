#include<bits/stdc++.h>
using namespace std;
int n;
int visited[1000000];
int arr[1000000];
int _map[14][14];
int ans=210000000;
void fuc(int m){
    if(m==n){//m==n이면 출력을 해야됨 실제는 n-1 때 갯수는 채워지니까까
        for(int i=0;i<n;i++){
            //cout<<arr[i]<<" ";
        }
        //cout<<endl;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(_map[arr[i]][arr[i+1]]==0) return ;
            //cout<<"map :"<<_map[arr[i]][arr[i+1]]<<"\n";
            sum+=_map[arr[i]][arr[i+1]];
        }
        if(_map[arr[n-1]][arr[0]]==0) return;
        sum+=_map[arr[n-1]][arr[0]];
        if(ans>sum) ans=sum;
        //cout<<"sum :"<<sum;
        //cout<<endl;
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        arr[m]=i;
        visited[i]=1;
        fuc(m+1);
        visited[i]=0;
    }
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>_map[i][j];
        }
    }
    fuc(0);
    cout<<ans;
}