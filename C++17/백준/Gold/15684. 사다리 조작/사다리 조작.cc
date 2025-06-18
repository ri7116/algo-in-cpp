#include<bits/stdc++.h>
using namespace std;


int cur_i;
int h,k,w;
int a,b,n;
int Map[1000][1000];
int chk;
void fuc(int depth,int cur){
    if(depth==n){
        for(int i=1;i<=h;i++){
            cur_i=i;
            for(int j=1;j<=w;j++){
                if(Map[j][cur_i-1]==1) cur_i--;
                else if(Map[j][cur_i]==1) cur_i++;
            }
            if(cur_i!=i) {//하나라도 다르면 뒤는 더 보지마 
                return;
            }
        }
        chk=1;//되는 경우 존재 체크
        return;
    }

    for(int i=cur;i<=(h-1)*w-1;i++){
        if(Map[1+(i/(h-1))][i%(h-1)+1+1]==1) continue;//오른쪽에 사다리 있으면 넘어가
        if(Map[1+(i/(h-1))][i%(h-1)+1]==1) continue;//현재 위치에 사다리 있으면 넘어가
        if(Map[1+(i/(h-1))][i%(h-1)+1-1]==1) continue;//왼쪽에 사다리 있으면 넘어가
        Map[1+(i/(h-1))][i%(h-1)+1]=1;
        fuc(depth+1,i+1);
        Map[1+(i/(h-1))][i%(h-1)+1]=0;
    }
}


int main(){
    cin>>h>>k>>w;//세로선 , 기존 가로선 갯수, 가로선 놓을 수 있는 위치의 개수 
    while(k--){
        cin>>a>>b;
        Map[a][b]=1;
    }

    chk=1;
    for(int i=1;i<=h;i++){
            cur_i=i;
            for(int j=1;j<=w;j++){
                if(Map[j][cur_i-1]==1) cur_i--;
                else if(Map[j][cur_i]==1) cur_i++;
            }
            if(cur_i!=i) chk=0;//하나라도 다르면
    }
    if(chk==1) {
        cout<<"0";
        return 0;
    }

    chk=0;
    n=1;
    fuc(0,0);
    if(chk==1) {
        cout<<"1";
        return 0;
    }

    chk=0;
    n=2;
    fuc(0,0);
    if(chk==1) {
        cout<<"2";
        return 0;
    }

    chk=0;
    n=3;
    fuc(0,0);
    if(chk==1) {
        cout<<"3";
        return 0;
    }

    cout<<"-1";

}