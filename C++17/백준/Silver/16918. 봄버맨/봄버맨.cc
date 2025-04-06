#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int cnt;
string str;
char arr[204][204];
queue <pair<int,int>> q;

int main(){
    cin>>n>>m>>t;
    //큐넣기
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            if(str[j]=='O') q.push({i,j+1});
            arr[i][j+1]=str[j];
        }
    }
    cnt++;//1초
    if(cnt==t){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        //cout<<"1초";
        return 0;
    }

    cnt++;//2초
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]='O';
        }
    }

    if(t%2==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<'O';
            }
            cout<<endl;
        }
        //cout<<"2초";
        return 0;
    }

    while(1){
        //폭발 and 큐넣기
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            arr[y-1][x]='.';
            arr[y][x-1]='.';
            arr[y+1][x]='.';
            arr[y][x+1]='.';
            arr[y][x]='.';
            q.pop();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]=='O') q.push({i,j});
            }
        }
        cnt++;//3초
        if(cnt==t){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<arr[i][j];
                }
                cout<<endl;
            }
            //cout<<"BOOM:"<<cnt;
            return 0;
        }

        cnt++;//4초
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                arr[i][j]='O';
            }
        }
    }
}