#include<bits/stdc++.h>
using namespace std;

int heap[10000000];
int sz = 0;  //heap에 들어있는 원소의 수

void push(int x){
    sz++;
    heap[sz]=x;

    int tmp=sz;
    while(1){
        if(tmp==1) break;
        if(heap[tmp/2]>heap[tmp]) swap(heap[tmp/2],heap[tmp]);
        tmp=tmp/2;
    }
}

int top(){ // 맨 위의 값?
    if(sz==0) return 0;//이 문제의 특수성
    return heap[1];
}

void pop(){
    if(sz==1) {
        sz--;
        return ;
    }
    if(sz==2) {
        heap[1]=heap[2];
        sz--;
        return ;
    }
    if(sz==3){
        sz--;
        heap[1]=heap[3];
        if(heap[2]<heap[1]) {
            swap(heap[1],heap[2]);    
        }
        return;
    }
    heap[1]=heap[sz];
    sz--;
    int tmp=1;
    while(1){
        if(2*tmp>sz) break;//if(2/tmp>=sz) 와 차이가 있음
        int ming=tmp*2;
        if(tmp*2+1 <=sz and heap[tmp*2+1]<heap[tmp*2]) ming=tmp*2+1;
        if(heap[tmp]<=heap[ming]) break;
        swap(heap[tmp],heap[ming]);
        tmp=ming;
        
        // if(heap[tmp*2]<heap[tmp]) {
        //     if(heap[tmp*2+1]<heap[tmp*2]){
        //         swap(heap[tmp*2+1],heap[tmp]);
        //         tmp=tmp*2+1;
        //     }
        //     else{
        //     swap(heap[tmp*2],heap[tmp]);
        //     tmp=tmp*2;
        //     }
        //}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k==0){
            cout<<top()<<'\n';
            if(top()!=0) {
                pop();
            }
             // for(int i=1;i<7;i++){
             //     cout<< heap[i]<<" ";
             // }
             // cout<<endl;
        }
        else{
            push(k);
            // for(int i=1;i<10;i++){
            //     cout<< heap[i]<<" ";
            // }
            // cout<<endl;
        }
    }
}