#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
    if(a.size()!=b.size())  return a.size()<b.size();
    if(a.size()==b.size()){
        int a_sum=0;
        int b_sum=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<='9') {a_sum+=a[i]-'0';
            //cout<<a[i]-'0'<<endl;
            }

        }
        for(int i=0;i<b.size();i++){
            if(b[i]<='9') {b_sum+=b[i]-'0';
            //cout<<b[i]-'0'<<endl;
            }
        }
        //cout<< "a_sum: "<<a_sum<<" b_sum :"<<b_sum<<endl;
        if(a_sum==b_sum){//사전순 정렬을 어케 구현?
            return a<b;
            
        }
        else{
            //cout<<"sum 이 같지 않습니다!"<<endl;
            return a_sum<b_sum;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string tmp;
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto k:v){
        cout<<k<<'\n';
    }
}
//체크포인트 1. 숫자인지 확인 1-1 isdisit() 1-2 아스키 코드=> 숫자 대문자 소문자
//체크포인트 2. 사전순은 a<b
