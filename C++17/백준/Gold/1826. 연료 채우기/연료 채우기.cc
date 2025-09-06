#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1000004];
int target;
int solid;
priority_queue<int> q;
int ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[a]=b;
    }
    cin>>target>>solid;
    for(int i=1;i<=target;i++){
        if(arr[i]!=0) q.push(arr[i]);//주유소면 일단 넣어주자
        solid--;
        if(i==target) break;
        if(solid==0){
            if(q.empty()) {
                cout<<"-1";
                return 0;
            }
            ans++;
            solid+=q.top();
            q.pop();
        }
    }
    cout<<ans;
}
//1. 그리디
//2. 1씩 움직이다가 더 이상 움직일 수 없으면 '우선순위 큐에 있었던' 가장 높은 연료를 주는 주유소를 들림
//3. DP가 안되는 이유는 https://hyeo-noo.tistory.com/262 참고
//4. 풀이 정보 https://oh2279.tistory.com/103