#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[100004];
long long min_=9876543219;

int main(){
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }

    long long st=0;
    long long ed=1000000000;
    while(st<=ed){
        long long cnt=1;
        long long mid=(st+ed)/2;
        long long cur=mid;
        for(long long i=0;i<n;i++){
            if(mid < arr[i]){//i번째 강의가 블루레이 한개의 크기보다 크면 녹화가 아예 불가능하므로
                cnt = m+1;
                break;
            }
            if(cur-arr[i]>=0) {
                cur-=arr[i];
                //cout<<cur<<endl;
            }
            else{
                cnt++;
                cur=mid;
                cur-=arr[i];
                //cout<<cur<<endl;
            }
        }
        //너무 많은 비디오 수
        if(cnt>m){
            //cout<<"cnt :"<<cnt<<endl;
            //cout<<"mid :"<<mid<<endl;
            st=mid+1;
        }
        //너무 적은 비디오수
        else if(cnt<m){
            //cout<<"cnt :"<<cnt<<endl;
            //cout<<"mid :"<<mid<<endl;
            min_=min(mid,min_);
            ed=mid-1;
        }
        //정답 비디오수
        //더 적은 답이 있지 않을까?
        //만약 더 큰 답이 있지 않을까? 라면 st=mid+1로 하면됨
        else{
            //cout<<"cnt :"<<cnt<<endl;
            //cout<<"mid :"<<mid<<endl;
            min_=min(mid,min_);
            ed=mid-1;
        }
    }
    cout<<min_;
}