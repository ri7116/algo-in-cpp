#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10000];
int a[10000];
int b[10000];
int ans;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i]>>a[i]>>b[i];
    }
    for(int i=123;i<999;i++){
        bool check=0;
        for(int j=0;j<n;j++){
            int tmp_a=0;
            int tmp_b=0;
            if((i%1000)/100==(arr[j]%1000)/100) tmp_a++; //스트라이크 갯수
            if((i%100)/10==(arr[j]%100)/10) tmp_a++;
            if((i%10)==(arr[j]%10)) tmp_a++;

            if((i%1000)/100==(arr[j]%100)/10) tmp_b++; //볼 갯수
            if((i%1000)/100==(arr[j]%10)) tmp_b++;
            if((i%100)/10==(arr[j]%1000)/100) tmp_b++;
            if((i%100)/10==(arr[j]%10)) tmp_b++;
            if((i%10)==(arr[j]%1000)/100) tmp_b++;
            if((i%10)==(arr[j]%100)/10) tmp_b++;
            if(a[j]!=tmp_a or b[j]!=tmp_b) check=1;
        }
        //3개의 자리수가 모두 달라야 함
        int back=(i%1000)/100;
        int ten=(i%100)/10;
        int one=i%10;
        if(back == 0 or  ten == 0 or one ==0) check=1;
        if(back == ten or back == one or ten == one) check=1;
        if(check==0) ans++;
    }
    cout<<ans;
}
//1. 3자리의 숫자는 모두 달라야 함
//2. 스트라이크 갯수 확인 로직 == 각자리의 숫자가 모두 같은지 보면 됨
//3. 볼 갯수 확인 로직 == 다른자리에 같은 숫자가 있는지 모두 보면 됨