#include<bits/stdc++.h>
using namespace std;
string start="";
string a;
vector<string> tmp[100];
int cnt;
int main(){
    getline(cin, a);  // 전체 라인을 읽어들임
    //cout<<"a: "<<a<<endl;
    cnt=0;
    //cout<<"asize: "<<a.size()<<endl;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==' ') 
        {
            cnt++;//공백을 어떻게 확인?
    //        cout<<"gong back"<<endl;
            continue;
        }
        if(cnt==0) {
            start.push_back(a[i]);//처음 글자는 start에 저장
    //        cout<<"start in"<<endl;
        }
        else {
            tmp[cnt-1].push_back(string(1,a[i]));//두번째부터는 tmp에 저장하기
    //        cout<<"tmp in"<<endl;
        }
    }
    //cout<<"cnt :"<<cnt<<endl;

    for(int i=0;i<cnt;i++){
        cout<<start;
        bool check=0;
        int lastidx=0;
        for(int j=tmp[i].size()-1;j>=0;j--){
            if(tmp[i][j]==",") continue;
            if("A"<=tmp[i][j] and tmp[i][j]<="Z" and check==0){
                cout<<" ";
                //<<tmp[i][j];
                lastidx=j;
                check=1;
                break;
            }
            else if("a"<=tmp[i][j] and tmp[i][j]<="z" and check ==0){
                cout<<" ";
                //<<tmp[i][j];
                lastidx=j;
                check=1;
                break;
            }
            else if(tmp[i][j]=="[") cout<<"]";
            else if(tmp[i][j]=="]") cout<<"[";
            else cout<<tmp[i][j];
        }
        for(int j=0;j<=lastidx;j++) cout<<tmp[i][j];
        cout<<";"<<endl;
    }
}
//vector<string> tmp[100];
//