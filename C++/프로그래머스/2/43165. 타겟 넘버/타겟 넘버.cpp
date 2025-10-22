#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ans=0;

void f(int SUM, int idx, int plus, vector<int>& numbers, int target){
    if(idx==numbers.size()) {
        if(SUM==target) ans++;
        return;
    }
    int nSUM=0;
    if(plus==1) nSUM=SUM + numbers[idx];
    else nSUM=SUM - numbers[idx];
    
    f(nSUM, idx+1, 1, numbers, target);
    f(nSUM, idx+1, 0, numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    f(0,0,1,numbers,target);
    f(0,0,0,numbers,target);
    answer=ans/2;
    return answer;
}