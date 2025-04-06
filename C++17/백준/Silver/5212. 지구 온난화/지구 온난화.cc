#include<bits/stdc++.h>
using namespace std;


int n,m;
int xStart=15,yStart=15;
int xMax,yMax;
string str;
char arr[14][14];//뭘로 채워지지? null인가?
queue <pair<int,int>> q;
int main(){
    cin>>n>>m;
    for(int i=0;i<14;i++){
        for(int j=0;j<14;j++){
            arr[i][j]='.';
        }
    }
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            arr[i][j+1]=str[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1][j]=='.' and arr[i][j-1]=='.' and arr[i+1][j]=='.' and arr[i][j+1]=='.') q.push({i,j});
            if(arr[i][j-1]=='.' and arr[i+1][j]=='.' and arr[i][j+1]=='.') q.push({i,j});
            if(arr[i-1][j]=='.' and arr[i+1][j]=='.' and arr[i][j+1]=='.') q.push({i,j});
            if(arr[i-1][j]=='.' and arr[i][j-1]=='.' and arr[i][j+1]=='.') q.push({i,j});
            if(arr[i-1][j]=='.' and arr[i][j-1]=='.' and arr[i+1][j]=='.') q.push({i,j});
        }
    }
    while(!q.empty()){
        arr[q.front().first][q.front().second]='.';
        q.pop();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // if(xStart==0 and yStart==0 and arr[i][j]=='X'){
            //     yStart=i;
            //     xStart=j;
            // }
            if(arr[i][j]=='X'){
                xMax=max(xMax,j);
                yMax=max(yMax,i);
                xStart=min(xStart,j);
                yStart=min(yStart,i);
            }
        }
    }
    for(int i=yStart;i<=yMax;i++){
        for(int j=xStart;j<=xMax;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
//1. i==0 or j==0인 경우는 그냥 비워두고 케이스 처리를 따로 하는 것보다 쉬움
