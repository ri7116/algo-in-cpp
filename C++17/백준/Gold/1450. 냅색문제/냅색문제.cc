
#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
vector<long long> weight1;
vector<long long> weight2;
vector<long long> sum1;
vector<long long> sum2;

void fuc1(long long idx,long long sum){
    if(idx==weight1.size()) {
        sum1.push_back(sum);
        return;  //탈출조건
    }
    //1. 물건을 넣는 경우
    fuc1(idx+1, sum+weight1[idx]);
    
    //2. 물건을 안 넣는 경우
    fuc1(idx+1, sum);
}

void fuc2(long long idx,long long sum){
    if(idx==weight2.size()) {
        sum2.push_back(sum);
        return;  //탈출조건
    }
    //1. 물건을 넣는 경우
    fuc2(idx+1, sum+weight2[idx]);
    
    //2. 물건을 안 넣는 경우
    fuc2(idx+1, sum);
}

int main(){
    cin>>n>>k;//물건개수 무게
    for(int i=0;i<n;i++){
        long long tmp;
        cin>>tmp;

        if(i<n/2) weight1.push_back(tmp);
        else weight2.push_back(tmp);
    }
    //1. sum1의 조합 만들기, sum2의 조합 만들기
    fuc1(0,0);
    fuc2(0,0);
    //서로 다른 물건에 순서 상관 없으니까 조합임
    sort(sum2.begin(),sum2.end());
    for(int i=0;i<sum1.size();i++){
        auto a=upper_bound(sum2.begin(),sum2.end(),k-sum1[i]); //return 이터레이터
        //cout<<a-sum2.begin()<<endl;
        ans+=a-sum2.begin();
    }
    cout<<ans;
}
//1. 절반 나눠서 하나를 기준으로 이분탐색
//2. 이거 뭔가 이분탐색 + 투포인터 + DP 느낌
//3. 하나의 배낭에 넣는 경우의 수인데 2^???인 느낌의 문제
//https://www.youtube.com/watch?v=nW5y7PFLR3M 참고