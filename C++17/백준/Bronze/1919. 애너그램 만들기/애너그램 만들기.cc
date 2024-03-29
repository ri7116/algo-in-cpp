#include<bits/stdc++.h>
using namespace std;
string a;
string b;

int c;
int main(){
    cin>>a>>b;
    int arr[104][2]={};
    for(char k: a) arr[k-'a'][0]++;    
    for(char k: b) arr[k-'a'][1]++;   
        for(int i=0;i<26;i++){
            if(arr[i][0] or arr[i][1]) {
                c+=abs(arr[i][0]-arr[i][1]);     
            }
        }
    cout<<c;
}