#include <string>
#include <vector>
#include <bits/stdc++.h>
//그리디 느낌이 났었는데 그리디가 맞았네
//끝 부분 정렬
//if(현재끝지점<=다음.first) 끝지점 옮기기
using namespace std;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}



int solution(vector<vector<int>> targets) {
    int answer = 0;
    for(int i=0;i<targets.size();i++){
        v.push_back({targets[i][0],targets[i][1]});
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=1;
    int pos=v[0].second;
    for(int i=1;i<v.size();i++){
        if(pos<=v[i].first){
            cnt++;
            pos=v[i].second;
        }
    }
    return answer=cnt;
}