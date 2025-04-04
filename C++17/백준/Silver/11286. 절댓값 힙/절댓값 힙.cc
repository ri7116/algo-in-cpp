#include<bits/stdc++.h>
using namespace std;

int n;


class cmp{
    public:
    bool operator()(int a,int b){
        if(abs(a)==abs(b)) return a>b;
        else if (abs(a)>abs(b)) return true;
        else return false;
    }
};


priority_queue<int,vector<int>, cmp> pq;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<0<<endl;
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
}
//b가 a보다 우선순위가 높음