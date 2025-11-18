#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//중복 조합 숫자요~
int arr[24];
int ans=2100000000;
int cnt[24];

void f(int n, int k, int cur, int idx, vector<vector<int>>& reqs) {
    if (idx == n) {
        fill(cnt, cnt + 24, 0); // cnt 초기화

        for (int i = 0; i < n; i++) {
            cnt[arr[i]]++;
        }

        // 각 유형별로 멘토가 최소 1명 이상인지 확인
        for (int i = 1; i <= k; i++) {
            if (cnt[i] == 0) return;
        }

        priority_queue<int, vector<int>, greater<int>> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        priority_queue<int, vector<int>, greater<int>> q3;
        priority_queue<int, vector<int>, greater<int>> q4;
        priority_queue<int, vector<int>, greater<int>> q5;

        int res_time = 0;

        for (int i = 0; i < reqs.size(); i++) {
            int start_time = reqs[i][0];
            int duration = reqs[i][1];
            int part_time = reqs[i][2]; // 상담 유형

            // 해당 유형의 멘토가 0명이면 계산 불가 (위에서 걸렀지만 안전장치)
            if (cnt[part_time] == 0) return;

            // ==========================================
            // [수정됨] 대기 시간 및 종료 시간 로직 적용
            // ==========================================
            
            if (part_time == 1) {
                if (q1.size() == cnt[1]) { // 꽉 찼으면
                    int prev_end_time = q1.top();
                    q1.pop();

                    // 실제 시작 시간 = max(이전 상담 끝난 시간, 내 도착 시간)
                    int real_start_time = max(prev_end_time, start_time);
                    
                    // 대기 시간 누적 (내가 도착했을 때 이미 상담중이었던 경우만)
                    if (real_start_time > start_time) {
                        res_time += (real_start_time - start_time);
                    }
                    
                    q1.push(real_start_time + duration);
                }
                else {
                    q1.push(start_time + duration);
                }
            }
            else if (part_time == 2) {
                if (q2.size() == cnt[2]) {
                    int prev_end_time = q2.top();
                    q2.pop();
                    int real_start_time = max(prev_end_time, start_time);
                    if (real_start_time > start_time) res_time += (real_start_time - start_time);
                    q2.push(real_start_time + duration);
                }
                else {
                    q2.push(start_time + duration);
                }
            }
            else if (part_time == 3) {
                if (q3.size() == cnt[3]) {
                    int prev_end_time = q3.top();
                    q3.pop();
                    int real_start_time = max(prev_end_time, start_time);
                    if (real_start_time > start_time) res_time += (real_start_time - start_time);
                    q3.push(real_start_time + duration);
                }
                else {
                    q3.push(start_time + duration);
                }
            }
            else if (part_time == 4) {
                if (q4.size() == cnt[4]) {
                    int prev_end_time = q4.top();
                    q4.pop();
                    int real_start_time = max(prev_end_time, start_time);
                    if (real_start_time > start_time) res_time += (real_start_time - start_time);
                    q4.push(real_start_time + duration);
                }
                else {
                    q4.push(start_time + duration);
                }
            }
            else if (part_time == 5) {
                if (q5.size() == cnt[5]) {
                    int prev_end_time = q5.top();
                    q5.pop();
                    int real_start_time = max(prev_end_time, start_time);
                    if (real_start_time > start_time) res_time += (real_start_time - start_time);
                    q5.push(real_start_time + duration);
                }
                else {
                    q5.push(start_time + duration);
                }
            }
        }
        ans = min(ans, res_time);
        return;
    }

    for (int i = cur; i <= k; i++) {
        arr[idx] = i;
        f(n, k, i, idx + 1, reqs);
    }
}


//잘못된 함수
//n은 멘토수, k는 상담 유형의 수 
// void f(int n,int k, int cur,int idx,vector<vector<int>>& reqs){
//     if(idx==n){
//         fill(cnt, cnt + 24, 0);//cnt 초기화 필요
        
//         for(int i=0;i<n;i++){
//             cnt[arr[i]]++;
//         }
        
//         // for(int i=0;i<n;i++){
//         //     cout<<arr[i]<<" ";
//         // }
//         // cout<<endl;
        
//         for(int i=1;i<=k;i++){
//             //cout<<cnt[i]<<" ";
//             if(cnt[i] == 0) return;
//         }
//         // cout<<endl;
        
//         // for(int i=1;i<=k;i++){
//         //     if(cnt[n] == 0) return ; //각 유형별로 멘토 인원이 적어도 한 명 이상이어야 한다.
//         // }
        
//         priority_queue<int, vector<int>, greater<int>> q1;
//         priority_queue<int, vector<int>, greater<int>> q2;
//         priority_queue<int, vector<int>, greater<int>> q3;
//         priority_queue<int, vector<int>, greater<int>> q4;
//         priority_queue<int, vector<int>, greater<int>> q5;
        
//         int res_time=0;
//         for(int i=0;i<reqs.size();i++){
//             int start_time = reqs[i][0];
//             int end_time = reqs[i][0]+reqs[i][1];
//             int part_time = reqs[i][2]; //상담 유형
            
//             if(cnt[part_time] == 0) return;//애초에 상담을 할 수 없으면 진행하지 말고 끝내버려
            
//             if(part_time == 1){
//                 if( q1.size() == cnt[1] && cnt[1] > 0){//다 찼으면
//                     int tmp = q1.top()-start_time;//기다린 시간 = 이전 상담 상담 종료시간 - 내가 기다리기 시작한 시간
//                     q1.pop();
//                     q1.push(end_time + tmp);
//                     if(tmp>=0) res_time+=tmp;
//                 }
//                 else{
//                     q1.push(end_time);
//                 }
//             }
            
//             if(part_time==2){
//                 if(q2.size()==cnt[2] && cnt[2] > 0){//다 찼으면
//                     int tmp=q2.top()-start_time;
//                     q2.pop();
//                     q2.push(end_time + tmp);
//                     if(tmp>=0) res_time+=tmp;
//                 }
//                 else{
//                     q2.push(end_time);
//                 }
//             }
            
//             if(part_time==3){
//                 if(q3.size()==cnt[3] && cnt[3] > 0){//다 찼으면
//                     int tmp=q3.top()-start_time;
//                     q3.pop();
//                     q3.push(end_time + tmp);
//                     if(tmp>=0) res_time+=tmp;
//                 }
//                 else{
//                     q3.push(end_time);
//                 }
//             }
            
//             if(part_time==4 && cnt[4] > 0){
//                 if(q4.size()==cnt[4]){//다 찼으면
//                     int tmp=q4.top()-start_time;
//                     q4.pop();
//                     q4.push(end_time + tmp);
//                     if(tmp>=0) res_time+=tmp;
//                 }
//                 else{
//                     q4.push(end_time);
//                 }
//             }
            
//             if(part_time==5 && cnt[5] > 0){
//                 if(q5.size()==cnt[5]){//다 찼으면
//                     int tmp=q5.top()-start_time;
//                     q5.pop();
//                     q5.push(end_time + tmp);
//                     if(tmp>=0) res_time+=tmp;
//                 }
//                 else{
//                     q5.push(end_time);
//                 }
//             }
//         }
//         ans=min(ans,res_time);
//         // cout<<res_time<<"로 잘 끝났습니다"<<endl;
//         return;
//     }
    
//     for(int i=cur;i<=k;i++){
//         arr[idx]=i;
//         f(n,k,i,idx+1,reqs);
//     }
// }


// vector<vector<int>> reqs [a, b, c] a분에서 a+b분까지 c번 유형의 상담을 원하는 참가자
// n은 멘토의 수, k는 상담 유형의 수
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    //중복 조합 코드를 구현 하자
    
    f(n,k,1,0,reqs);
    answer=ans;
    return answer;
}

//시뮬레이션 같은데?