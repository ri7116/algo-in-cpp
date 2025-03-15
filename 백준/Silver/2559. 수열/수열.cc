#include<bits/stdc++.h> //누적합!
using namespace std;
int N, K, temp, MAX;
int arr[10000001], sum[10000001];
int main(){
cin>>N >> K;
for(int i=1; i<=N;i++){//배열에 입력받기 
    cin>>arr[i];
    temp+=arr[i];
    sum[i]+=temp;
}

MAX=sum[K];

for(int i=K+1;i<=N;i++){
    if(sum[i]-sum[i-K]>=MAX) MAX=sum[i]-sum[i-K];
}

cout<< MAX;
}
//1. 누적합(위의 코드)
//2. 슬라이딩 윈도우