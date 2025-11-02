#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long ans=2100000000;

// 이거 그냥 이분탐색이네 ㅋㅋ 킼킼 근데 함수 구현이 좀 까다롭다긔?
long long f(int level, vector<int>& diffs,vector<int>& times){
    long long res=0;
    for(int i=0;i<diffs.size();i++){
        if(diffs[i]<=level)    {
            //cout<<times[i]<<"추가"<<endl;
            res+=times[i];
        }
        else {
            //cout<<(diffs[i]-level)*(times[i]+times[i-1])+times[i]<<"추가"<<endl;
            res+=(diffs[i]-level)*(times[i]+times[i-1])+times[i];
        }
    }
    //cout<<level<<"사용한 시간"<<res<<endl;
    return res;
}

//return level
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    //level이 기준
    long long st=1;
    long long ed=2100000000;
    while(st<=ed){
        long long mid=(st+ed)/2;
        if(limit>=f(mid,diffs,times)){
            ed=mid-1;
            ans=min(ans,mid);
        }
        else{
            st=mid+1;
        }
    }
    
    answer=ans;
    return answer;
}