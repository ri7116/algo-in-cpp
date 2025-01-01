#include<bits/stdc++.h>
using namespace std;
string a;

int main(){
    cin>> a;
    int ans= a.size();
    for(int i=0;i<a.size();i++){
        if(i+1==a.size()) continue;//범위 나가는거 방지
        if(a[i]=='c'){
            if(a[i+1]=='=' or a[i+1]=='-') ans--;
        }
        if(a[i]=='l'){
            if(a[i+1]=='j') ans--;
        }

        if(a[i]=='n'){
            if(a[i+1]=='j') ans--;
        }
        if(a[i]=='s'){
            if(a[i+1]=='=') ans--;
        }
        if(a[i]=='d'){
            if(a[i+1]=='-') ans--;
        }
        if(a[i]=='z'){
            if(a[i+1]=='=') {
                ans--;
                if(a[i-1]=='d'){
                    ans--;
                }
            }
        }
    }
    cout<<ans;
}