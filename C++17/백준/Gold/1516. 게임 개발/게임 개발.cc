#include<bits/stdc++.h>
using namespace std;
int n;
int Time[1004];
int ans[1004];
int indegree[1004];
int a;
vector<int> v[1004];
queue<int> q;  // 부모 정보 불필요, 노드 번호만 저장

int main(){
    cin>>n;
    //입력 넣기 
    for(int i=1;i<=n;i++){
        cin>>a;
        Time[i]=a;
        while(1){
            cin>>a;
            if(a==-1) break;
            else {
                indegree[i]++;
                v[a].push_back(i);
            }
        }
    }

    //위상정렬 시작 부분 넣기
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);  // 노드 번호만 저장
            ans[i] = Time[i];  // 선행 건물이 없으므로 자신의 시간만 필요
        }
    }

    //위상정렬 부분
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto next : v[current]){
            // 모든 선행 건물 중 최대 시간을 고려
            ans[next] = max(ans[next], ans[current] + Time[next]);
            
            indegree[next]--;
            if(indegree[next]==0) {
                q.push(next);
            }
        }
    }

    //정답 출력
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
}