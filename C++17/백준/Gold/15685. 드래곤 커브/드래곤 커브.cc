#include<bits/stdc++.h>
using namespace std;
int k;
int n;
int Map[101][101] = {};
deque <tuple<int,int,int>> dq;
deque <tuple<int,int,int>> tmp;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

void fuc(int depth){
    //맵에 어떻게 칠할건가?
    if(depth==n){
        while(!dq.empty()){
            int _y=get<0>(dq.front());
            int _x=get<1>(dq.front());
            int _z=get<2>(dq.front());
            dq.pop_front();
            if(_z==0){
                Map[_y][_x]=1;
                Map[_y][_x+1]=1;
            }
            if(_z==1){
                Map[_y][_x]=1;
                Map[_y-1][_x]=1;
            }
            if(_z==2){
                Map[_y][_x]=1;
                Map[_y][_x-1]=1;
            }
            if(_z==3){
                Map[_y][_x]=1;
                Map[_y+1][_x]=1;
            }
            // cout<<_y<<" "<<_x<<" "<<_z<<"\n";
        }
    //    cout<<"=============\n";
        return;
    }
    // 복사 덱에 넣기
    for(int i=0;i<dq.size();i++){
        tmp.push_back(dq[i]);
    }
    //복사 뒤부터 빼면서 90도 회전후 큐에 넣기
    int cnt=0;
    int y,x,d,cur_y,cur_x,nd;
    while(!tmp.empty()){
        if(cnt==0){
            y=get<0>(tmp.back());
            x=get<1>(tmp.back());
            d=get<2>(tmp.back());
            tmp.pop_back();
            
            cur_y=y+dy[d];
            cur_x=x+dx[d];
            nd=(d+5)%4;
            dq.push_back({cur_y,cur_x,nd});      
            cnt++;
        }
        else{
            d=get<2>(tmp.back());
            tmp.pop_back();
            
            cur_y=cur_y+dy[nd];//이전에 저장된 방향으로 이동
            cur_x=cur_x+dx[nd];//이전에 저장된 방향으로 이동
            nd=(d+5)%4;// 새로운 방향으로
            dq.push_back({cur_y,cur_x,nd});        
        }

    }
    fuc(depth+1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>k;
    while(k--){
        int a,b,c;
        cin>>a>>b>>c>>n;
        dq.push_back({b,a,c});
        fuc(0);
        dq.clear();
        tmp.clear();
    }
    int ans=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(Map[i][j] > 0 && Map[i+1][j] > 0 && Map[i][j+1] > 0 && Map[i+1][j+1] > 0) {
                ans++;
            }
        }
    }
    // for(int i=0;i<7;i++){
    //     for(int j=0;j<7;j++){
    //         cout<<Map[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans;
}
//1. 스택에 넣고 하나씩 빼면서 90도 회전하기
//2. n-2 n-2 까지 전부 오른쪽, 아래, 오른쪽 아래가 1인지 체크하기