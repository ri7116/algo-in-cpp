//1. LIS의 길이
//2. LIS의 원본 배열 출력
#include<bits/stdc++.h>
using namespace std;
int n, lis[1000004], len, num;
pair<int,int> ans[1000004];
stack<int> stk;
const int INF=1e9+4;
int main(){
    fill(lis,lis+1000004,INF);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        auto lowerPos=lower_bound(lis,lis+len,num);
        if(*lowerPos==INF) len++;//해당 값이 초기화 되어있지 않으면 맨뒤에 추가 해야하는데 len이 1개 증가함
        *lowerPos=num;
        int _pos=lowerPos-lis;
        ans[i].first=_pos;//lis 배열의 idx
        ans[i].second=num;//lis 배열의 값
    }
    cout<<len<<endl;
    //뒤에서부터 가장 큰 수부터 작은 수를 흝음 
    for(int i=n-1;i>=0;i--){
        if(ans[i].first==len-1){
            stk.push(ans[i].second);
            len--;
        }
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
