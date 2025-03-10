#include <bits/stdc++.h>
using namespace std;
int a, cnt, ch, k;
string patturn;
string str;
char star='*';

int main(){
cin>>a; // 횟수 입력받기
cin>>patturn; //패턴 입력받기
for(int i=0;i<patturn.size();i++){// *위치 확인하기
                cnt++;
               //cout<<cnt<< endl;
                if(star==patturn[i]) break; 
}
for(int i=0;i<a;i++){
cin>>str;
k=0;
while(1){
                if(str.size()<(patturn.size()-1)) { //패턴확인 할 str이 작으면 틀린으로 출력
                                cout<<"NE"<< endl;
                                break;
                }
                for(int i=0;i<cnt-1;i++){
                                if(patturn[i]!=str[i]){
                                                
                                                k=10;
                                                break;
                                }
                }
                if(k==10){
                                cout<<"NE"<<endl;
                                break;
                }
                for(int i=0;i<patturn.size()-cnt;i++){
                                if(patturn[patturn.size()-i-1]!=str[str.size()-i-1]){ //-1 넣어야 할까 말아야 할까?
                                                cout<<"NE"<<endl;
                                                k=10;
                                                break;
                                }
                }
                if(k!=10){
                cout<<"DA"<<endl;
                }
                break;
         }
}
}