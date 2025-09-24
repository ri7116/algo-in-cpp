
#include<bits/stdc++.h>
using namespace std;

int arr[11][11];
int ans=987654321;
int paper[6];

//스티커를 붙일 수 있는가?
bool possible(int r,int c,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[r+i][c+j]==0) return false;
        }
    }
    return true;
}

void dfs(int r, int c, int cnt){
    // 1을 찾을 때까지는 포인터가 계속 움직인다!
    while(arr[r][c]==0){
        c++;//오른쪽으로 한칸
        if(c >=10){//한줄 아래로
            r++;
            if(r>=10){
                ans=min(ans,cnt);
                return;
            }
            c=0; 
        }
    }
    if(cnt>=ans) return; 

    //1을 만났음 스티커를 큰거부터 작은거로 붙임.
    for(int i=5;i>=1;i--){
        if(r+i>10 or c+i >10) continue;//지도 벗어나면 스킵!
        if(paper[i]>=5) continue;//종이는 최대 5개!

        if(possible(r, c, i)){
            paper[i]++;
            for(int a=0;a<i;a++){
                for(int b=0;b<i;b++){
                    arr[r+a][c+b]=0;
                }
            }
            dfs(r,c,cnt+1);
            //원복
            paper[i]--;
            for (int a = 0; a < i; a++){
				for (int b = 0; b < i; b++)
				{
					arr[r + a][c + b] = 1;
				}
            }
		}
    }
}







int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,0,0);
    if(ans==987654321) ans=-1;
    cout<<ans;
}
//https://fisher10001.tistory.com/13
//나중에 다시 풀어야 됨 개어렵네..