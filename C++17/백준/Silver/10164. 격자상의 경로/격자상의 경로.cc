#include<bits/stdc++.h>
using namespace std;

int d[1000][1000];
int n,m,k;
int cnt;

int main(){
    cin>>n>>m>>k;
    if(k==0) k=-1;
    for(int i=0;i<1;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]!=0) continue;

            d[i][j]=1;
            cnt++;
            if(cnt==k){
                int hang=k/m;
                int yal=k%m;
                for(int ii=yal;ii<m;ii++){
                    d[i][ii]=d[i][j];
                }
                for(int ii=hang;ii<n;ii++){
                    d[ii][j]=d[i][j];
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]!=0) continue;
            d[i][j]=d[i-1][j]+d[i][j-1];
            cnt++;
            if(cnt==k-1){
                int hang=k/m;
                int yal=k%m;
                for(int ii=yal;ii<m;ii++){
                    d[i][ii]=d[i][j];
                }
                for(int ii=hang;ii<n;ii++){
                    d[ii][j]=d[i][j];
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<d[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<d[n-1][m-1];
}