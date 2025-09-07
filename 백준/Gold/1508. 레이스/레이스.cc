#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long arr[1000004];
string real_ans="!!";
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    long long st=1;
    long long ed=n;
    while(st<=ed){
        long long mid=(st+ed)/2;
        
        long long cnt=1;
        long long prev=0;
        string ans="1";
        for(int i=1;i<k;i++){
            if(arr[i]-arr[prev]>=mid and cnt<m){//중요! cnt<m
                cnt++;
                prev=i;
                ans+="1";
            }
            else ans+="0";
        }
        //cout<<mid<<" : "<<ans<<endl;
        

        if(cnt==m){//m개를 만족하면 거리를 더 늘려볼까?
            real_ans=ans;
            st=mid+1;
        }
        else if(cnt>m){
            st=mid+1;
        }

        else{//m개를 만족하지 않으면 거리를 줄여볼까?
            ed=mid-1;
        }
    }
    cout<<real_ans;
}
//1. 사전순일 때 맨 앞에 1인 이유와
//2. 정답 정답 오답일 때 다른 사람들은 어떻게 걸렀을까?
//3. 그리디라고 종합 문제집에 있었지만 결국은 파라메트릭서치(이분 탐색)
// cnt<m을 넣어야 정답이 나오네?
