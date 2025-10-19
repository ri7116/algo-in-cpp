#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(auto a:clothes){
        mp[a[1]]++;
    }
    for(auto a: mp){
        answer*=(a.second+1);
    }
    answer--;
    return answer;
}