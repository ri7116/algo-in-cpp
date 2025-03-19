#include <vector>
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int solution(vector<int> nums)
{
    int answer = 0;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    cout<<mp.size();
    if(mp.size()>nums.size()/2) answer=nums.size()/2;
    if(mp.size()==nums.size()/2) answer=nums.size()/2;
    if(mp.size()<nums.size()/2) answer=mp.size();
    
    return answer;
}