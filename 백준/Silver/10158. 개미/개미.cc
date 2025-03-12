#include<bits/stdc++.h>
using namespace std;
int w,h;
int x,y;
int cnt;
int main(){
    cin>>w>>h;
    cin>>x>>y;
    cin>>cnt;

    x+=cnt;
    y+=cnt;
    //cout<<"==========";
    //cout<<x<<" : "<<y<<endl;
    //cout<<"==========";
    //cout<<w*2-1<<" : "<<h*2<<endl;
    int ans_x=x%(w*2);
    int ans_y=y%(h*2);
    //cout<<"==========";
    //cout<<ans_x<<" : "<<ans_y<<endl;
    if(ans_x>w) ans_x=(w*2)-ans_x;
    if(ans_y>h) ans_y=(h*2)-ans_y;
    cout<<ans_x<<" "<<ans_y;
}