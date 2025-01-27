#include<bits/stdc++.h>
using namespace std;
int n;
string d[1004];
int main(){
  cin>>n;
  d[1]="SK";//""SK" ==잡은사람이 이김" "2는 후턴"
  d[2]="CY";//후턴이
  d[3]="SK";//잡은사람이
  d[4]="CY"; // 3 "SK" / "SK" 3 / "SK" 1 1 1
  for(int i=5;i<=1000;i++){
    if(d[i-1]== "CY" or d[i-3]== "CY" ) d[i]="SK";
    else d[i]="CY"; 
  }
  cout<<d[n];
}