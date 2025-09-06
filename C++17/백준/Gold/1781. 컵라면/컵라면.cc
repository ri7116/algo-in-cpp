
// #include<bits/stdc++.h>
// using namespace std;
// struct st{
//     long long a;
//     long long b;

//     bool operator<(struct st other){
//         if(this->a==other.a){
//             return this->b>other.b;// 내림차순
//         }
//         else{
//             return this->a<other.a;// 오름차순
//         }
//     }
// };

// vector<struct st> v;
// int n;
// long long ans=0;
// long long deadline=0;


// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         long long a,b;
//         cin>>a>>b;
//         struct st tmp;
//         tmp.a=a;
//         tmp.b=b;
//         v.push_back(tmp);
//     }
//     sort(v.begin(),v.end());
//     //cout<<"========================\n";
//     for(int i=0;i<n;i++){
//         //cout<<v[i].a<<" : "<<v[i].b<<endl;
//         if(v[i].a>deadline){
//             ans+=v[i].b;
//             deadline=v[i].a;
//         }
//     }
//     cout<<ans;
// }
//1. 그리디 
//2. this랑 other의 차이?
//3. 첫번째 잘못된 풀이
#include<bits/stdc++.h>
using namespace std;
struct st{
    long long a;
    long long b;

    bool operator<(struct st other){
        if(this->a==other.a){
            return this->b>other.b;// 내림차순
        }
        else{
            return this->a<other.a;// 오름차순
        }
    }
};

vector<struct st> v;
int n;
long long ans=0;
priority_queue<int,vector<int>,greater<int>> q; //오름차순 pq

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        struct st tmp;
        tmp.a=a;
        tmp.b=b;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    //cout<<"========================\n";
    for(auto k:v){
        if(k.a>q.size()){
            q.push(k.b);
        }
        else if(k.a<=q.size() and k.b>q.top()){
            q.pop();
            q.push(k.b);
        }
    }
    while(!q.empty()){
        //cout<<q.top()<<endl;
        ans+=q.top();
        q.pop();
    }
    cout<<ans;
}
//큐의 사이즈가 데드라인이고 그 데드라인 안에는 그 날짜까지 라면을 많이주는 문제를 넣으면 됨