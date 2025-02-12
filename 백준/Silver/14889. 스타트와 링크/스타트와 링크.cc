#include<bits/stdc++.h>
using namespace std;
int n;
int ans=2100000000;
int arr[21];
int visited[21];
int score[21][21];
void fuc(int m,int next){
    if(m==n/2){
        int team[21];
        for(int i=0;i<n;i++){
            team[i]=0;
        }
        int score_a=0;
        int score_b=0;
        for(int i=0;i<n/2;i++){
            //cout<<arr[i]<<" ";
            team[arr[i]]=1;
        }
        //cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(team[i]==1){
                    if(team[j]==1){
                        score_a+=score[i][j];
                    }
                }
                else{
                    if(team[j]==0){
                        score_b+=score[i][j];
                    }
                }
            }
        }
        //cout<<"a:b = "<<score_a<<" "<<score_b<<endl;
        int result=abs(score_a-score_b);
        //cout<<result<<endl;
        if(ans>result) ans= result;

    }

    for(int i=next;i<n;i++){
        if(visited[i]) continue;
        arr[m]=i;
        visited[i]=1;
        fuc(m+1,i+1);
        visited[i]=0;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>score[i][j];
        }
    }
    fuc(0,0);
    cout<<ans;
}