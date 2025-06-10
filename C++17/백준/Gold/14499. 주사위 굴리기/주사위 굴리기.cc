#include<bits/stdc++.h>
using namespace std;
int cur_x,cur_y;
int n,m;
int k;
int Map[30][30];
int dice[10];
void move(int w){
    //동
    if(w==1){
        int tmp1=dice[1];
        int tmp2=dice[2];
        int tmp3=dice[3];
        int tmp4=dice[4];
        int tmp5=dice[5];
        int tmp6=dice[6];
        dice[4]=tmp6;
        dice[1]=tmp4;
        dice[3]=tmp1;
        dice[6]=tmp3;
        if(Map[cur_y][cur_x]==0){
            Map[cur_y][cur_x]=dice[6];
        }
        else{
            dice[6]=Map[cur_y][cur_x];
            Map[cur_y][cur_x]=0;
        }
    }
    //서
    if(w==2){
        int tmp1=dice[1];
        int tmp2=dice[2];
        int tmp3=dice[3];
        int tmp4=dice[4];
        int tmp5=dice[5];
        int tmp6=dice[6];
        dice[4]=tmp1;
        dice[1]=tmp3;
        dice[3]=tmp6;
        dice[6]=tmp4;
        if(Map[cur_y][cur_x]==0){
            Map[cur_y][cur_x]=dice[6];
        }
        else{
            dice[6]=Map[cur_y][cur_x];
            Map[cur_y][cur_x]=0;
        }
    }
    //북
    if(w==3){
        int tmp1=dice[1];
        int tmp2=dice[2];
        int tmp3=dice[3];
        int tmp4=dice[4];
        int tmp5=dice[5];
        int tmp6=dice[6];
        dice[2]=tmp6;
        dice[1]=tmp2;
        dice[5]=tmp1;
        dice[6]=tmp5;
        if(Map[cur_y][cur_x]==0){
            Map[cur_y][cur_x]=dice[6];
        }
        else{
            dice[6]=Map[cur_y][cur_x];
            Map[cur_y][cur_x]=0;
        }
    }
    //남
    if(w==4){
        int tmp1=dice[1];
        int tmp2=dice[2];
        int tmp3=dice[3];
        int tmp4=dice[4];
        int tmp5=dice[5];
        int tmp6=dice[6];
        dice[2]=tmp1;
        dice[1]=tmp5;
        dice[5]=tmp6;
        dice[6]=tmp2;
        if(Map[cur_y][cur_x]==0){
            Map[cur_y][cur_x]=dice[6];
        }
        else{
            dice[6]=Map[cur_y][cur_x];
            Map[cur_y][cur_x]=0;
        }
    }
    
}



int main(){
    cin>>n>>m>>cur_y>>cur_x>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Map[i][j];
        }
    }
    while(k--){
        int a;
        cin>>a;
        if(a==1){
            cur_x++;
            if(cur_x<0 or cur_x>=m or cur_y<0 or cur_y>=n) {
                cur_x--;
                continue;
            }
        }
        if(a==2){
            cur_x--;
            if(cur_x<0 or cur_x>=m or cur_y<0 or cur_y>=n) {
                cur_x++;
                continue;
            }
        }
        if(a==3){
            cur_y--;
            if(cur_x<0 or cur_x>=m or cur_y<0 or cur_y>=n) {
                cur_y++;
                continue;
            }
        }
        if(a==4){
            cur_y++;
            if(cur_x<0 or cur_x>=m or cur_y<0 or cur_y>=n) {
                cur_y--;
                continue;
            }
        }
        move(a);

        // for(int i=1;i<=6;i++){
        //     cout<<dice[i]<<" ";
        // }
        // cout<<endl;
        
        cout<<dice[1]<<endl;

    }
}