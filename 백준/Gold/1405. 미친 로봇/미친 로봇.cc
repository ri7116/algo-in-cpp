#include<bits/stdc++.h>
using namespace std;
int visited[1000][1000];
int dx[4]={0,1,0,-1};//북동남서
int dy[4]={1,0,-1,0};
int arr[15];
int po[4];//동서남북
double ans;
int n;

void fuc(int depth,int x, int y){
    if(depth==n){
        double tmp=1;
        for(int i=0;i<n;i++){
            tmp*=0.01*po[arr[i]];
            //cout<<arr[i]<<" ";
        }
        //cout<<endl;
        ans+=tmp;
        return;
    }

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(visited[ny][nx]) {
            //cout<<"방문햇어요\n";
            continue; // return이 맞나?
        }
        arr[depth]=i;
        visited[ny][nx]=1;
        fuc(depth+1,nx,ny);
        visited[ny][nx]=0;
    }
}


int main(){
    cin>>n>>po[1]>>po[3]>>po[2]>>po[0];
    visited[500][500]=1;
    fuc(0,500,500);
    cout << fixed << setprecision(9) << ans;
}
//1. 방문전에 시작점을 방문처리
//2. 자료형 생각하기