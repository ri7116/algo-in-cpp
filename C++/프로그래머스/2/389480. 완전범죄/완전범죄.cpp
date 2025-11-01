#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int Case[9];
// 정렬이 아니라 dp였네
// b는 내림차순 이면서 a는 크게 

//1. 정렬문제가 아니네?
//2. 브루트포스 반복문도 아니네?
//3. DP인가?


int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    for(int i=0;i<info.size();i++){
        //0 1 3 6 4 2 7 5 8
        if(info[i][0]==3 and info[i][1]==1) Case[0]++;
        if(info[i][0]==2 and info[i][1]==1) Case[1]++;
        if(info[i][0]==1 and info[i][1]==1) Case[2]++;
      
        if(info[i][0]==3 and info[i][1]==2) Case[3]++;
        if(info[i][0]==2 and info[i][1]==2) Case[4]++;
        if(info[i][0]==1 and info[i][1]==2) Case[5]++;
        
        if(info[i][0]==3 and info[i][1]==3) Case[6]++;
        if(info[i][0]==2 and info[i][1]==3) Case[7]++;
        if(info[i][0]==1 and info[i][1]==3) Case[8]++;
    }

    while(m>1){
        //0 1 3 2
        // 4 6 5 7 8
        if(Case[0]>0 and m>=2) {
            Case[0]--;
            m-=1;
        }
        else if(Case[1]>0 and m>=2) {
            Case[1]--;
            m-=1;
            cout<<m<<endl;
        }
        
        else if(Case[3]>0 and m>=3) {
            Case[3]--;
            m-=2;
        }
        
        
        else if(Case[6]>0 and m>=4) {
            Case[6]--;
            m-=3;
        }
        else if(Case[4]>0 and m>=3) {
            Case[4]--;
            m-=2;
        }
        else if(Case[2]>0 and m>=2) {
            Case[2]--;
            m-=1;
        }
        else if(Case[7]>0 and m>=4) {
            Case[7]--;
            m-=3;
        }
        
        else if(Case[5]>0 and m>=3) {
            Case[5]--;
            m-=2;            
        }
        
        
        else if(Case[8]>0 and m>=4) {
            Case[8]--;
            m-=3;
        }
        //빠져나갈 조건
        //B에서 끝나는 경우
        //m은 절대 0이 될 수 없음
        if(Case[0] == 0 and Case[1] == 0 and Case[2] == 0 and Case[3] == 0 and Case[4] == 0 and Case[5] == 0 and Case[6] == 0 and Case[7] == 0 and Case[8] == 0) {
            return answer=0;
        }
        
        //m == 4면 모든 경우를 커버 가능해서 while문 한 번 더 돈다.
        if(m==3 and (Case[3] == 0 and Case[4] == 0 and Case[5] == 0 and Case[0] == 0 and Case[1] == 0 and Case[2] == 0)) break;//2나 1로 돌게 없으면 그냥 break;
        if(m==2 and (Case[0] == 0 and Case[1] == 0 and Case[2] == 0)) break;//1로 돌게 없으면 break;
        if(m==1) break;
    }
    int res=0;
    res+=Case[0]*3;
    res+=Case[1]*2;
    res+=Case[2]*1;
    res+=Case[3]*3;
    res+=Case[4]*2;
    res+=Case[5]*1;
    res+=Case[6]*3;
    res+=Case[7]*2;
    res+=Case[8]*1;
    if(res>=n) return -1;
    else return res;
    
}