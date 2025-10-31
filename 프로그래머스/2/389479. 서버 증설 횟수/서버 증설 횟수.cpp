#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int cnt=0;
queue<pair<int,int>> q;
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int CurOkPeople=m-1;
    
    for(int i=0;i<players.size();i++){
        if(!q.empty() and q.front().first==i){
            int rentSeverNum=q.front().second;
            q.pop();
            cout<<i<<"서버 반납\n";
            CurOkPeople-=m*rentSeverNum;
        }
        if(players[i]>=CurOkPeople){
            //서버를 빌려야해 
            
            int newSeverNum=(players[i]-CurOkPeople)/m;
            if((players[i]-CurOkPeople)%m!=0) newSeverNum++;
            cnt+=newSeverNum;
            cout<<i<<"시간에"<<newSeverNum<<"대 빌림";
            
            CurOkPeople+=m*newSeverNum;
            q.push({i+k,newSeverNum});
            
        }
    }
    answer=cnt;
    return answer;
}