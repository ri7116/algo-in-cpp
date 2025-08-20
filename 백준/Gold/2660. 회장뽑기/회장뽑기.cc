#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int a,b;
int arr[104][104];
int ans_num=1000000004;
int tmp[104];

int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=1000000000;
            if(i==j) arr[i][j]=0;
        }
    }

    while(1){
        cin>>a>>b;
        if(a==-1 and b==-1) break;
        arr[a][b]=1;
        arr[b][a]=1;
    }


    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]>arr[i][k]+arr[k][j]) arr[i][j]=arr[i][k]+arr[k][j];
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        int c=-1;
        for(int j=1;j<=n;j++){
            c=max(c,arr[i][j]);//c는 각각의 위치의 최단경로 중 가장 긴 것;
        }
        tmp[i]=c;
        ans_num=min(ans_num, tmp[i]);// ans_num은 각각의 최단경로중 가장 작은 것
    }
    // cout<<"ans 넘의 값"<<" "<<ans_num<<'\n';
    for(int i=1; i<=n; i++){
        if(tmp[i]==ans_num) ans.push_back(i);
    }
    cout<<ans_num<<" "<<ans.size()<<'\n';
    for(auto a:ans){
        cout<<a<<" ";
    }

}
//배열을 무한대로 세팅하고 나서 arr[a][b]를 넣어줌을 주의하자!
//벨만포드 문제