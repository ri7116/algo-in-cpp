#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int visited[104];
int real_ans=999999999;

bool isChange(string str1, string str2){
    int cnt=0;
    
    for(int i=0;i<str1.size();i++){
        if(str1[i]==str2[i]) cnt++;
    }
    
    if(cnt==str1.size()-1) return true;
    else return false;
}

//dfs + 원복
void f(string begin, string target ,vector<string> words,int ans){
    if(begin == target) {
        real_ans=min(real_ans,ans);
        return ;
    }
    
    for(int i=0;i<words.size();i++){
        if(isChange(begin, words[i]) && !visited[i]){
            visited[i]=1;
            f(words[i], target, words, ans+1);
            visited[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    f(begin,target,words,0);
    
    answer=real_ans;
    if(answer==999999999) answer=0;
    return answer;
}
//n^2풀이 