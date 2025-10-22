#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int visited[204];
queue<int> q;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int row = computers[0].size();
    for(int i=0;i<row;i++){
        if(!visited[i]){//i를 방문하지 않았다면 방문해서 네트워크 수 찾자!
                answer++;
                q.push(i);
                visited[i]=1;
                
                while(!q.empty()){
                    int cur=q.front();
                    q.pop();
                    
                    for(int k=0;k<row;k++){
                        if(computers[cur][k]==1 && !visited[k]){
                            q.push(k);
                            visited[k]=1;
                        }
                    }
                }
        }
    }
    
    
//     for(int i=0;i<row;i++){
//         for(int j=0;j<row;j++){
//             if(i==j) continue;
            
//             if(computers[i][j] == 1 && !visited[i]){//i를 방문하지 않았다면 방문해서 네트워크 수 찾자!
//                 answer++;
//                 q.push(i);
//                 visited[i]=1;
                
//                 while(!q.empty()){
//                     int cur=q.front();
//                     q.pop();
                    
//                     for(int k=0;k<row;k++){
//                         if(computers[cur][k]==1 && !visited[k]){
//                             q.push(k);
//                             visited[k]=1;
//                         }
//                     }
//                 }
                
//             }
//         }
//     }
    
    return answer;
}