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
        
        // for(int i=1;i<=9;i++){
        //     cout<<Map[i][1]<<" ";
        // }
        // cout<<endl;

        for(int i=1;i<=n;i++){//이닝
            int cnt=0;
            //루 초기화
            for(int j=1;j<=9;j++){
                Map[j][2]=0;
            }
            //이닝 시작 알림
            
            // cout<<"ening start \n";


            while(1){
                taza++;
                if(taza>=10) taza=taza-9;
                
                //cout<<taza<<" gogogogo\n";
                
                if(ening_map[i][Map[taza][1]]==1){ // 1루타
                    // 3루에 있던 주자는 득점
                    for(int k=1; k<=9; k++) if(Map[k][2] == 3) { Map[k][2] = 4; }
                    // 2루에 있던 주자는 3루로
                    for(int k=1; k<=9; k++) if(Map[k][2] == 2) { Map[k][2] = 3; }
                    // 1루에 있던 주자는 2루로
                    for(int k=1; k<=9; k++) if(Map[k][2] == 1) { Map[k][2] = 2; }
                    
                    // 타자는 1루로
                    Map[taza][2] = 1;

                    // 점수 계산 및 베이스 정리
                    for(int k=1; k<=9; k++){
                        if(Map[k][2] >= 4) {
                            tmp++;
                            Map[k][2] = 0;
                        }
                    }
                }
                if(ening_map[i][Map[taza][1]]==2){ // 2루타
                    // 3루, 2루 주자는 득점
                    for(int k=1; k<=9; k++) if(Map[k][2] == 3 || Map[k][2] == 2) { 
                        tmp++; 
                        Map[k][2] = 0; // 즉시 베이스에서 제거
                    }
                    // 1루 주자는 3루로
                    for(int k=1; k<=9; k++) if(Map[k][2] == 1) { Map[k][2] = 3; }

                    // 타자는 2루로
                    Map[taza][2] = 2;
                }
                if(ening_map[i][Map[taza][1]]==3){ // 3루타
                    // 모든 주자는 득점
                    for(int k=1; k<=9; k++) {
                        if(Map[k][2] > 0) {
                            tmp++;
                            Map[k][2] = 0;
                        }
                    }
                    // 타자는 3루로
                    Map[taza][2] = 3;
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