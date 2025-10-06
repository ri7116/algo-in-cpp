#include<bits/stdc++.h>
using namespace std;

map <string,int> mp;

vector<int> p(400004,-1);
int ansCount[400004];
int find(int x){
	if(p[x]<0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v){
	u=find(u);
	v=find(v);
	
	if(u==v) return false;
		
	if(p[v] < p[u]) swap(u, v);// u가 v보다 트리의 높이가 더 큼을 보장(흡수 해도 높이가 바뀌지 않음)
	if(p[u] == p[v]) p[u]--; //같은 랭크(트리의 높이)에 대한 처리

    ansCount[u]+=ansCount[find(v)];// ^^ 파티의 개수처리!
	p[v]=u;//v의 부모는 u;
	return true;
}

int t;
int n;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>t;

    while(t--){
        cin>>n;
        mp.clear();
        for(int i=0;i<400004;i++){
            p[i]=-1;
            ansCount[i]=1;//1로 정의함!
        }
        string a, b;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(mp.find(a)==mp.end() and mp.find(b)==mp.end()){
                cnt++;
                mp[a]=cnt;
                cnt++;
                mp[b]=cnt;
                uni(mp[a],mp[b]);
                cout<<ansCount[find(mp[a])]<<"\n";
            }
            else if(mp.find(a)!=mp.end() and mp.find(b)==mp.end()){
                cnt++;
                mp[b]=cnt;
                uni(mp[a],mp[b]);
                cout<<ansCount[find(mp[a])]<<"\n";
            }
            else if(mp.find(a)==mp.end() and mp.find(b)!=mp.end()){
                cnt++;
                mp[a]=cnt;
                uni(mp[a],mp[b]);
                cout<<ansCount[find(mp[a])]<<"\n";
            }
            else if(mp.find(a)!=mp.end() and mp.find(b)!=mp.end()){
                uni(mp[a],mp[b]);
                cout<<ansCount[find(mp[a])]<<"\n";
            }
        }
    }
}