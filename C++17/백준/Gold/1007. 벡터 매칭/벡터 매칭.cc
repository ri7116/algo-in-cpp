#include<bits/stdc++.h>
using namespace std;

double ans; // 결과값은 double
int N;      // 개수는 int
int t;      // 개수는 int
int visited[24];
double a, b; // 좌표는 double

vector<pair<double, double>> v;

void dfs(int cur, int cnt, int n){
    if(cnt == n/2){
        double st_x=0;
        double st_y=0;
        double ed_x=0;
        double ed_y=0;

        for(int i=0; i<n; i++){
            if(visited[i]==1){
                st_x+=v[i].first;
                st_y+=v[i].second;
            }
            else{
                ed_x+=v[i].first;
                ed_y+=v[i].second;
            }
        }
        
        double dx = ed_x - st_x;
        double dy = ed_y - st_y;
        ans = min(ans, sqrt(dx * dx + dy * dy));
        return;
    }

    for(int i=cur; i<n; i++){
        visited[i]=1;
        dfs(i+1, cnt+1, n);
        visited[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    
    cout.precision(12);
    cout << fixed;

    while(t--){
        cin >> N;
        
        ans = 1e18; 
        v.clear();
        
        for(int i=0; i<N; i++){
            visited[i]=0;
        }

        for(int i=0; i<N; i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        
        dfs(0, 0, N);
        
        cout << ans << '\n';
    }
}


// 조합(재귀) + 수학
// 1. 
// cout.precision(12);
// cout << fixed;