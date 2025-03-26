#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[100004];
long long min_=9876543219;

int main(){
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }

    long long st=0;
    long long ed=n-1;
    //같으면 안되니까
    while(st<ed){
        long long sum=arr[st]+arr[ed];
        if(sum>0) {
            ed--;
            if(abs(sum)<abs(min_)) min_=sum;
            //cout<<"sum: "<<sum<<endl;
        }
        else if(sum<0){
            st++;
            if(abs(sum)<abs(min_)) min_=sum;
            //cout<<"sum: "<<sum<<endl;
        }
        else{
            //cout<<"sum: "<<sum<<endl;
            min_=sum;
            break;
        }
    }
    cout<<min_;
}
//이분탐색으로 푼거 맞나? 투포인터랑 다른게 뭐지?....