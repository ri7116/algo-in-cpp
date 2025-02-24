#include<bits/stdc++.h>
using namespace std;


int m,n;
int cnt;
int ans=0;
string ans_str;
vector<string> v;
int arr[1004][4];
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    for(int i=0;i<n;i++){
        for(auto a:v){
            if(a[i]=='A')arr[i][0]++;
            if(a[i]=='C')arr[i][1]++;
            if(a[i]=='G')arr[i][2]++;
            if(a[i]=='T')arr[i][3]++;
        }
    }
    for(int i=0;i<n;i++){
        int max_cnt=0;
        int max_idx=0;
        for(int j=0;j<4;j++){
            if(arr[i][j]>max_cnt){
                max_cnt=arr[i][j];
                max_idx=j;
            }
        }
        if(max_idx==0) ans_str+='A';
        if(max_idx==1) ans_str+='C';
        if(max_idx==2) ans_str+='G';
        if(max_idx==3) ans_str+='T';
        ans+=m-max_cnt;
    }
    cout<<ans_str<<'\n';
    cout<<ans;
}
//열마다 틀린 문자열의 갯수는 무엇?
//열 기준으로 생각하기 사전순은 '>='이 아닌 '>'로 해결