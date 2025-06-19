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

            while(1){
                taza++;
                if(taza>=10) taza=taza-9;

                int hit = ening_map[i][Map[taza][1]];

                if(hit == 0){ // 아웃
                    cnt++;
                    if(cnt >= 3) break;
                    continue;
                }

                // 안타 또는 홈런:
                // 1. 현재 주자 위치를 백업하고, 맵을 깨끗하게 비운다.
                int current_bases[10] = {0};
                for(int k=1; k<=9; k++){
                    current_bases[k] = Map[k][2];
                    Map[k][2] = 0; // 베이스를 비운다
                }

                // 2. 백업된 정보로 모든 주자를 진루시킨다.
                for(int k=1; k<=9; k++){
                    if(current_bases[k] > 0){ // k번째 타순의 선수가 주자로 있었다면
                        int new_pos = current_bases[k] + hit;
                        if(new_pos >= 4){
                            tmp++; // 득점
                        } else {
                            Map[k][2] = new_pos; // 새로운 위치로 이동
                        }
                    }
                }

                // 3. 타자를 처리한다.
                if(hit == 4){ // 홈런인 경우 타자도 득점
                    tmp++;
                } else { // 안타인 경우 타자를 해당 베이스로 이동
                    Map[taza][2] = hit;
                }
            }
        }
        ans=max(ans,tmp);
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