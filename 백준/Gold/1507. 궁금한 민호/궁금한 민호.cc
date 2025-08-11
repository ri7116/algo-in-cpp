#include<bits/stdc++.h>
using namespace std;

int arr[21][21];
bool notdirect[21][21];


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if (k == i or i == j or j == k) //서로 다른 두 도시의 경우에서만
                    continue;
                if(arr[i][j]>arr[i][k]+arr[k][j]){
                    cout<<"-1";
                    return 0;
                }
                //이 부분이 뭘까?
                // if(i!=k and j!=k and (arr[i][k] + arr[k][j]) == arr[i][j])
                if(arr[i][k] + arr[k][j] == arr[i][j]) notdirect[i][j]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!notdirect[i][j]) cnt+=arr[i][j];//직접 연결된 도로(양방향 데스네)
        }
    }
    cout<<cnt/2;
}
//1. 플로이드 와샬을 역으로 이용하는 문제
//2. i k k j가 존재하다면  i j 는 필요 없음(두 노드로 구할 수 있으니간)
//3. i j 가 i k k j 보다 더 크다면 모순임(i j 가 최단경로임이 주어졌으니까)
//(번외) 간선이 하나든지 두개이상이든지 문제가 없음 최단경로는 하나라