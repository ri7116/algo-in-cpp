#include<bits/stdc++.h>
using namespace std;
int n;
string d[1004];
int main(){
  cin>>n;
  d[1]="CY";//""SK" ==잡은사람이 이김" "2는 후턴"
  d[2]="SK";//후턴이
  d[3]="CY";// 1 1 1 //선턴이 짐
  d[4]="SK"; // 1 3 // 3 1 // 1 1 1 1
  for(int i=5;i<=1000;i++){
    //4 1// 3 2
    if(d[i-1]== "SK" or d[i-3]== "SK") d[i]="CY";
    else d[i]="SK"; 
  }
  cout<<d[n];
}