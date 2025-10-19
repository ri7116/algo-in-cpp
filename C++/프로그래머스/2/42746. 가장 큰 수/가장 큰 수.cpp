#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool cmp (const string &a, string &b) {
    if (a + b > b + a)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v2;
    for(auto a: numbers){
        v2.push_back(to_string(a));
    }
    sort(v2.begin(),v2.end(), cmp);
    for(auto a: v2){
        answer+=a;
    }
    ///0000이면?
    if(answer.size()>=2 and answer[0]=='0') answer="0"; 
    return answer;
}