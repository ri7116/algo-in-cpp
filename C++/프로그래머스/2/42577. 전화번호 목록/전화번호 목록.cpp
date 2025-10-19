#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
map <string,int> mp;
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i=0;i<phone_book.size();i++){
        mp[phone_book[i]]++;
    }
    //0부터 phone_book[i].size()-1까지 그냥 검색하면 되는 것이야.
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book[i].size()-1;j++){
            if(mp[phone_book[i].substr(0,j+1)]==1) answer=false;
        }
    }
    
    return answer;
}