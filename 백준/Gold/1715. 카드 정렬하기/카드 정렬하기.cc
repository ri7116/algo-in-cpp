#include<bits/stdc++.h>
using namespace std;
int main() {
    //priority_queue<int> pq;  
    priority_queue<int, vector<int>, greater<int>> pq;

    // 우선순위 큐에 원소를 삽입 (push) 한다 
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }

    // int idx=pq.top();
    // pq.pop();

    // int sum=idx;
    // idx=pq.top();
    // pq.pop();
    // sum=sum+idx;
    if(pq.size()==1){
        cout<<0;
        return 0;
    }
    if(pq.size()==2){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        cout<<a+b;
        return 0;
    }
    int real=0;
    while (pq.size()!=1) {
        int sum=0;
        int a=pq.top();
        pq.pop();
        // sum=sum+idx;
        int b=pq.top();
        pq.pop();
        sum=a+b;
        pq.push(sum);
        real += sum;
        
        //cout<<sum<<'\n';
    }
    cout<<real;
}