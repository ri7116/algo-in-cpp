#include<bits/stdc++.h>
using namespace std;
int k;
int n;
//조합
int arr[3];
int num[1004];
int ans;
set <int> s;
void fuc(int depth, int cur){
    if(depth==2){

        int b=(arr[0]+arr[1])/2;
        //cout<<arr[0]<<" "<<b<<" "<<arr[1]; 
        //cout<<arr[0]<<" "<<arr[1];
        //cout<<endl;                            
        if(b<=arr[0]) return; //b<a
        if(b>=arr[1]) return; //b>c
        if(abs(b-arr[0]!=abs(arr[1]-b))) return; //뺀 절대값이 같지 않다면 return;
        if(s.find(b)!=s.end()) {
            ans++; //b가 안에 있다면?
            //cout<<"ans++\n";
        }
        return ;
    }
    for(int i=cur; i<n;i++){
        arr[depth]=num[i];
        fuc(depth+1,i+1);
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>k;
    while(k--){
        ans=0;
        s.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num[i];
            s.insert(num[i]);
        }
        sort(num,num+n);
        fuc(0,0);
        cout<<ans<<endl;
    }
}
//1번째 풀이: nC3 10초 걸림 => n^3
//2번째 풀이: nC2+logN(set)+nlongN(정렬) => n^2