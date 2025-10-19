#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=0;i<=10000;i++){
        auto a=lower_bound(citations.begin(),citations.end(),i);
        int idx=a-citations.begin();
        if(citations.size()-idx>=i and idx<=i){
            answer=max(answer,i);
        }        
    }
    return answer;
}