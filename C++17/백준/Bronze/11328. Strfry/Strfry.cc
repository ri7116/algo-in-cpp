#include<bits/stdc++.h>
using namespace std;
string a;
string b;

int c;
int main(){
    cin>>c;
    for(int j=0;j<c;j++){
    cin>>a>>b;
    int arr[104][2]={};
    if(a.size()!=b.size()){
        cout<<"Impossible"<<endl;
        continue;
    }
    for(char k: a) arr[k-'a'][0]++;    
    for(char k: b) arr[k-'a'][1]++;   
        for(int i=0;i<26;i++){
            if(arr[i][0]!=0 and  (arr[i][0]!=arr[i][1])) {
                cout<<"Impossible"<<endl;
                break;
            } 
            if(i==25 and (arr[i][0]==arr[i][1])) cout<< "Possible"<<endl;
        }
    }
}