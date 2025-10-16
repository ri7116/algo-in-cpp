#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> v;
    deque<int> answer;
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(answer[answer.size()-1]!=arr[i]) answer.push_back(arr[i]);    
    }
    for(auto a: answer){
        v.push_back(a);
    }
    return v;
}