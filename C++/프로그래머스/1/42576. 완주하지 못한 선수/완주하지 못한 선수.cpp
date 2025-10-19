#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0;i<participant.size();i++){
        if(mp.find(participant[i]) == mp.end()) mp[participant[i]]=1;
        else mp[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++){
        mp[completion[i]]--;
    }
    for(auto a: mp){
        if( a.second != 0) answer = a.first;
    }
    
    return answer;
}