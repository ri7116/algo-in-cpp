#include<bits/stdc++.h>
using namespace std;
int q;
int n;
int f;
int c;
int cnt=1;
int p[100000];
int find(int x){
    if(p[x]<0) return x;//좌표 압축! 
    else return p[x]=find(p[x]);
}

bool uni(int u,int v){
    int uroot=find(u);
    int vroot=find(v);
    if(uroot==vroot) return false; //이미 부모가 같음 
    else {
        p[vroot]=uroot;
        return true;//합침
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>> q;
    while(q--){
        cout<<"Scenario "<<cnt++<<":\n"; 
        cin>> n;//나중에 여기부터 q while 넣어야 함
        for(int i=0;i<n;i++){
            p[i]=-1;
        }
        cin>>f; //친구수
        for(int i=0;i<f;i++){
            int a,b;
            cin>>a>>b;
            uni(a,b);
        }
        cin>>c;
        for(int i=0;i<c;i++){
            int a,b;
            cin>>a>>b;
            if(find(a)==find(b)) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        cout<<'\n';
    }

}