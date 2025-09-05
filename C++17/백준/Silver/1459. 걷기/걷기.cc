
#include<bits/stdc++.h>
using namespace std;
long long x,y,a,b;
long long ans=0;

int main(){
    cin>>x>>y>>a>>b;
    if(x>y) swap(x,y);// x가 항상 더 작게
    if(2*a<=b)  ans+=x*2*a;
    else ans+=x*b;
    x=y-x;
    //cout<<ans<<endl;
    //cout<<x<<endl;
    if(x%2==0){//짝수
        if(a<b) ans+=x*a;
        else ans+=x*b;
    }
    else{//홀수
        if(a<b) ans+=x*a;
        else {
            ans+=(x-1)*b;
            ans+=a;
        }
    }
    cout<<ans;
}
//1. 그리디 알고리즘 
//2. *2이상이라면 한칸 이동에 대각선 1이 될 수 있음