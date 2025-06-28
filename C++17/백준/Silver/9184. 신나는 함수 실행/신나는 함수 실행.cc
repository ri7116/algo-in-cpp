#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int dp[54][54][54];

int w(int a,int b,int c){
    if (a <= 0 || b <= 0 || c <= 0) return 1;//배열에 음수 idx는 들어가면 안됨 음수 체크 먼저 

    if(dp[a][b][c]!=0) return dp[a][b][c];// 이미 계산되어 있으면 계산되어 있는 값 return;

    if (a > 20 or b > 20 or c > 20) return dp[a][b][c] = w(20, 20, 20);
    // if (a <= 0 || b <= 0 || c <= 0) return dp[a][b][c]=1;
    if (a < b and b < c) return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else return dp[a][b][c]= w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(){
    
    while(1){
        cin>>a>>b>>c;
        if(a==-1 and b==-1 and c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<"\n";
    }
}
//재귀함수는 항상 return dp[a][b][c]= 재귀함수 어쩌고 저쩌고임 
//배열에 음수 idx가 들어가면 안됨을 주의하자