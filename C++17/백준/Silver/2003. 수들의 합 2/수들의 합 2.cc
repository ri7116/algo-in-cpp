#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[100005];
int mn= 0x7fffffff;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    int st=0;
    int ed=0;
    int sum=a[0];
    // while(st<=ed and ed<n)  
    // 입력
    // 4 1
    // 1 2 3 1
    // 출력
    // 1
    // 답
    // 2
    while(ed<n){
        if(sum>m){//m보다 크다면
            sum-=a[st];
            st++;
        }
        else if(sum<m){ //m보다 작다면
            ed++;
            sum+=a[ed];
        }

        else {//같다면
           cnt++;
           sum-=a[st];
           st++; 
        }
    }
    cout<<cnt;
}