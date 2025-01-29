#include<bits/stdc++.h>
using namespace std;
int n;
string d[1004];
int main(){
  cin>>n;
  d[1]="CY";// 받은사람이 짐
  d[2]="SK";// 받은 사람이 이김
  d[3]="CY";// 받은 사람이 짐 1 1 1 // 3
  d[4]="SK"; // 받은사람이 이김 1 3//
  for(int i=5;i<=1000;i++){
    if(d[i-1]== "CY" or d[i-3]== "CY" or d[i-4]== "CY" ) d[i]="SK";
    else d[i]="CY"; 
  }
  cout<<d[n];
}