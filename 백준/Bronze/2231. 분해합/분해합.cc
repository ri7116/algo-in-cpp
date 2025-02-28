#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i=1;i<1000000;i++){
        int tmp=i;
        int tmp_sum=i;
        
        while(tmp>0){
            tmp_sum+=tmp%10;
            tmp/=10;
        }
        //cout<<tmp_sum<<endl;
        if(tmp_sum==n){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}
// 변수명 헷갈리게 하지말자 완전탐색