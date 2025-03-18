#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<>> q; //min heap
int cnt;
bool ck;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++) q.push(scoville[i]);
    if(!q.empty() and q.top()>=K) return 0;
    while (!q.empty()) {
        //cout << q.top() << " ";  // 가장 높은 우선순위의 요소 출력
        cnt++;
        if(q.empty()) break;
        int temp=q.top();
        if(q.empty()) break;
        q.pop();
        if(q.empty()) break;
        int tempp=q.top();
        if(q.empty()) break;
        q.pop();
        q.push(temp+tempp*2);
        if(q.top()>=K) {
            ck=1;
            break;
        }
    }
    if(ck==1) answer=cnt;
    else answer=-1;
    return answer;
}


// 1. auto a = begin(), end() 있어야 됨 벡터 느낌으로
// 2. priority_queue<int,vector<int>,greater<>> q; //min heap
// 3. top pop 전에는 꼭 비어있는지 확인