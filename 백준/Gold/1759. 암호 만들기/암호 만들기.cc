#include<bits/stdc++.h>
using namespace std;

int n,r;
char tmp[20];
char arr[20];
int visited[20];
void fuc(int m,int t){
    if(arr[m-2]>arr[m-1]) return ;// 사전순 x 끝내버려
    if(m==n){
        if(t>=1 and m-t>=2){//모음 있으면 출력
            for(int i=0;i<m;i++){
                cout<<arr[i];
            }   
            cout<<endl;
        }
    }

    for(int i=0;i<r;i++){
        if(visited[i]) continue;
        arr[m]=tmp[i];
        visited[i]=1;
        if(arr[m]=='a' or arr[m]=='e' or arr[m]=='i' or arr[m]=='o' or arr[m]=='u' ){//모음있으면!
            fuc(m+1, t+1);
            visited[i]=0;
        }
         else{
             fuc(m+1, t+0);
             visited[i]=0;
         }
    }
}

int main(){
    cin>>n>>r;
    for(int i=0;i<r;i++){
        cin>>tmp[i];
    }
    sort(tmp,tmp+r);
    fuc(0,0);
}