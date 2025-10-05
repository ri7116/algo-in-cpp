#include<bits/stdc++.h>
using namespace std;
int n,m;
int indegree[1004];
int score[1004][1004];
int ans[1004];
int Prev[1004];
vector<int> last;
vector<int> v[1004];
queue<int> q;
vector<int> real_Prev;
void fuc(int x){
    if(x==1) {
        return ;
    }
    //cout<<x<<"방문이요\n";
    real_Prev.push_back(x);
    fuc(Prev[x]);
}

int main(){
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        score[a][b]=c;
        v[a].push_back(b);
        if(b==1) last.push_back(a);
        else indegree[b]++;//1의 indegree를 증가시키면 0인 경우가 두번 생겨서 문제가 생길 수 잇음
    }
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto next : v[cur]){
            if(ans[next]<ans[cur]+score[cur][next]){
                ans[next]=ans[cur]+score[cur][next];
                Prev[next]=cur;
            }
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
        }
    }
    int real_score=0;
    int real_index;
    for(auto ed: last){
        if(real_score<ans[ed]+score[ed][1]){
            real_score = ans[ed]+score[ed][1];
            real_index = ed;
        }
    }
    cout<<real_score<<'\n';
    real_Prev.push_back(1);
    fuc(real_index);
    real_Prev.push_back(1);
    for(int i=real_Prev.size()-1; i>=0 ;i--){
        cout<<real_Prev[i]<<" ";
    }
    // for(auto qwer: real_Prev){
    //     cout<<qwer<<" ";
    // }
}
//dp + 사이클이 있다고 착각하기 쉽네(꼬았어)