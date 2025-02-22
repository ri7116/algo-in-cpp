#include<bits/stdc++.h>
using namespace std;


int n;
int r;
int arr[100];
int visited[100];
int arr2[100];
set <string> s;
void fuc(int depth){
    if(depth==r){
        string str="";
        for(int i=0;i<r;i++){
            str+=to_string(arr2[i]);
        }
        s.insert(str);
        return;
    }
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        arr2[depth]=arr[i];
        visited[i]=1;
        fuc(depth+1);
        visited[i]=0;
    }
}


int main(){
    cin>>n;
    cin>>r;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    fuc(0);
    cout<<s.size();
}