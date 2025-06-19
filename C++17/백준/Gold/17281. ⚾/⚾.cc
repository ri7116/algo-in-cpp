#include<bits/stdc++.h>
using namespace std;
int ans=-1234567890;
int n;
int ening_map[54][14];
int Map[14][2];//선수번호(1),몇루인가(2)?
int visited[14];
int taza;
void dfs(int depth){
    if(depth==10){
        int tmp=0;
        taza=0;
        for(int i=1;i<=n;i++){//이닝
            int cnt=0;
            //루 초기화
            for(int j=1;j<=9;j++){
                Map[j][2]=0;
            }
            //이닝 시작 알림
            //cout<<"ening start \n";


            while(1){
                taza++;
                if(taza>=10) taza=taza-9;
                //cout<<taza<<" gogogogo\n";
                if(ening_map[i][Map[taza][1]]==1){//i번째 이닝의 taza의 선수 번호 
                    for(int k=1;k<=9;k++){//1번타자 부터 흝고
                        if(Map[k][2]!=0){// 경기장에 있으면
                            Map[k][2]=Map[k][2]+1;
                            if((Map[k][2])>=4){
                                Map[k][2]=0;
                                tmp++;
                            }
                        }
                    }
                    Map[taza][2]=1;
                }
                if(ening_map[i][Map[taza][1]]==2){
                    for(int k=1;k<=9;k++){//1번타자 부터 흝고
                        if(Map[k][2]!=0 ){// 경기장에 있으면
                            Map[k][2]=Map[k][2]+2;
                            if((Map[k][2])>=4){
                                Map[k][2]=0;
                                tmp++;
                            }
                        }
                    }
                    Map[taza][2]=2;
                }
                if(ening_map[i][Map[taza][1]]==3){
                    for(int k=1;k<=9;k++){//1번타자 부터 흝고
                        if(Map[k][2]!=0){// 경기장에 있으면
                            Map[k][2]=Map[k][2]+3;
                            if((Map[k][2])>=4){
                                Map[k][2]=0;
                                tmp++;
                            }
                        }
                    }
                    Map[taza][2]=3;
                }
                if(ening_map[i][Map[taza][1]]==4){
                    for(int k=1;k<=9;k++){//1번타자 부터 흝고
                        if(Map[k][2]!=0){// 경기장에 있으면
                            Map[k][2]=0;
                            tmp++;
                        }
                    }
                    tmp++;//자기 자신 승점
                }
                if(ening_map[i][Map[taza][1]]==0){
                    cnt++;
                    if(cnt>=3) {
                        break;
                    }
                }
            }
        }
                //map[j][1]; !//j번타자 선수번호 
                //ening_map[i][map[j][1]]; !//i이닝에서 j번 타자의 타점
                // if(ening_map[i][Map[j][1]]==1){
                //     for(int k=1;k<=9;k++){//1번타자 부터 흝고
                //         if(Map[k][2]!=0){// 경기장에 있으면
                //             Map[k][2]=Map[k][2]+1;
                //             if((Map[k][2]+1)>=4){
                //                 Map[k][2]=0;
                //                 tmp++;
                //             }
                //         }
                //     }
                // }
        ans=max(ans,tmp);
        //cout<<"fianl\n";
        return;
    }

    for(int i=2;i<=9;i++){
        if(visited[i]) continue;
        Map[depth][1]=i;//depth번 타자의 선수번호는 i
        
        visited[i]=1;//사용

        if(depth+1==4) dfs(depth+2);
        else dfs(depth+1);

        visited[i]=0;//원복
    }
}



int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            cin>>ening_map[i][j];
        }
    }
    Map[4][1]=1;//4번 타자의 선수번호는 1
    visited[1]=1;
    dfs(1);
    cout<<ans;
}
//1. cout<<으로 디버깅하다가 혼자 삽질함.. 
//2.         if(depth+1==4) dfs(depth+2);
//           else dfs(depth+1);                 depth 건너뛰기는 처음 경험.