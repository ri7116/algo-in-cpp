#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long sum1;
long long tmpsum;
long long tmp;
vector <long long >v;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    // for(int i=0;i<v.size();i++){
    //    cout<<v[i]<<" ";
    // }
    //cout<<'\n';
    for(int i=0;i<v.size();i++){
        if(i==0){
            ans=v[0];
            tmp=v[0];
            sum1++;
            tmpsum++;
            continue;
        }
        if(i!=0 and v[i]==v[0]){//첫번째 빈도 카운트
            sum1++;
            tmpsum++;
            continue;
        }
        if(v[i]!=tmp){//숫자가 바꼈을때
            //cout<<"숫자가 바꼈습니다 sum1 : tmpsum "<<sum1<<" "<<tmpsum<<endl;
           // cout<<"                 ans : tmp "<<ans<<" "<<tmp<<endl;

            if(sum1<tmpsum) {ans=tmp; //현재의 합이 더 크면 ans change 이부분 잘 보자 
            sum1=tmpsum;
            }
            tmp=v[i]; //tmp 초기설정
            tmpsum=1; 
            continue;
        }

        if(v[i]==tmp) tmpsum++; //빈도 체크

        if(i==v.size()-1){
            //cout<<"배열의 마지막 입니다 sum1 : tmpsum "<<sum1<<" "<<tmpsum<<endl;
           // cout<<"                 ans : tmp "<<ans<<" "<<tmp<<endl;
            if(sum1<tmpsum) ans=tmp; //현재의 합이 더 크면 ans change
        }

    }

    cout<< ans;
}