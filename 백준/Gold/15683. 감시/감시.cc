#include<bits/stdc++.h>
#define X first
using namespace std;

int n,k;
int cnt;
int ans=2100000000;
char map_[10][10];
char tmp[10][10];
vector<pair<int,int>> loc;
vector<pair<char,int>> cctv;
void fuc(int m){
    if(m==cnt){//배열 계산
        for(int i=0;i<cnt; i++){
            if(cctv[i].first=='1' and cctv[i].second==0){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
            }
            if(cctv[i].first=='1' and cctv[i].second==1){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
            }
            if(cctv[i].first=='1' and cctv[i].second==2){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            if(cctv[i].first=='1' and cctv[i].second==3){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
            }
            //2
            if(cctv[i].first=='2' and cctv[i].second==0){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            if(cctv[i].first=='2' and cctv[i].second==1){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
            }


            //5
            if(cctv[i].first=='5' and cctv[i].second==0){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            //4-0 x+가없음
            if(cctv[i].first=='4' and cctv[i].second==0){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            //4-1 x-가없없
            if(cctv[i].first=='4' and cctv[i].second==1){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            
            //4-2 y+가 없없
            if(cctv[i].first=='4' and cctv[i].second==2){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            //4-3 y-가 없없
            if(cctv[i].first=='4' and cctv[i].second==3){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
            }
            
            //3-0
            if(cctv[i].first=='3' and cctv[i].second==0){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
            }
            
            //3-1
            if(cctv[i].first=='3' and cctv[i].second==1){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx+1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }
            
            //3-2
            if(cctv[i].first=='3' and cctv[i].second==2){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny-1;
                }
            }

            
            //3-3
            if(cctv[i].first=='3' and cctv[i].second==3){
                int ny=loc[i].first;
                int nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    nx=nx-1;
                }
                ny=loc[i].first;
                nx=loc[i].second;
                while(1){
                    if(nx<0 or ny<0 or nx>=k or ny>=n or map_[ny][nx]=='6') break;
                    map_[ny][nx]='#';
                    ny=ny+1;
                }
            }
        }
        



        int sharp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(map_[i][j]=='0') sharp++;
            }
        }
        if(sharp<ans) ans=sharp;//사실은 0임임

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<k;j++){
        //         cout<<map_[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<"==========\n";

        for(int i=0;i<n;i++){//원복
            for(int j=0;j<k;j++){
                map_[i][j]=tmp[i][j];
            }
        }
        return;
    }

        if(cctv[m].first=='1'){
            //cout<<"1입니두\n";
            for(int j=0;j<4;j++){
                cctv[m].second=j;
                fuc(m+1);
            }
        }
        if(cctv[m].first=='2'){
            for(int j=0;j<2;j++){
                cctv[m].second=j;
                fuc(m+1);
            }
        }
        if(cctv[m].first=='3'){
            for(int j=0;j<4;j++){
                cctv[m].second=j;
                fuc(m+1);
            }
        }
        if(cctv[m].first=='4'){
            for(int j=0;j<4;j++){
                cctv[m].second=j;
                fuc(m+1);
            }
        }
        if(cctv[m].first=='5'){
                cctv[m].second=0;
                fuc(m+1);
        }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){//맵 입력
        for(int j=0;j<k;j++){
            char a;
            cin>>a;
            map_[i][j]=a;
            tmp[i][j]=a;
            if('1'<=a and a<='5'){
                loc.push_back({i,j});//y, x
                cctv.push_back({a,0});// a는 문자임에 주의의
                cnt++;
            }
        }
    }
    fuc(0);
    //cout<<cnt;
    cout<<ans;
}