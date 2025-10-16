#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t = 0;
    queue<int> q;
    int cur_weight=0;
    int idx=0;
    while(idx<truck_weights.size() ){//큐가 비어있지 않고 트럭 사이즈가 idx보다 작으면
        t++;
        if(q.size() == bridge_length){
            int tmp=q.front();
            q.pop();
            //cout<<t<<" "<<tmp<<"다리에서 내려요 \n";
            cur_weight-=tmp;
        }
        
        if(cur_weight+truck_weights[idx]<=weight){ //2.트럭이 새로 올라 갈 수 있을때
            //cout<<t<<" "<<truck_weights[idx]<<"트럭 다리로 올라가요\n";
            q.push(truck_weights[idx]);
            cur_weight+=truck_weights[idx];
            idx++;
        }
        else{
            q.push(0);
        }
    }
    t+=bridge_length; //마지막 트럭이 길이 만큼 가면 끝나니까 끝이겠지 뭐
    return t;
}