#include <bits/stdc++.h>

using namespace std;
int t,a,d[54][54];
string s; 
char b[54][54];
bool check[54][54];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
bool in(int aa,int bb){
    return(1<=aa && aa<=t && 1<=bb && bb<=a);
}  
int down(int y,int x){
    //종료조건(기저 사례)
    if(!in(y, x) || b[y][x] == 'H') return 0;
    
    //무한 반복이 존재하는지 체크하기
    if(check[y][x]){
        cout << -1 << "\n";
        exit(0);
    } 

    //dp[y][x] 계산한 적이 있으면 그냥 그걸 주고
    if(d[y][x]) return d[y][x];

    //계산한 적이 없다면 계산해서 리턴하자
    check[y][x] = 1;
    int value = (int)b[y][x] - '0';
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        d[y][x]= max(d[y][x],down(ny,nx) + 1);
    }
    check[y][x] = 0;
    return d[y][x];
}
int main(){
    cin >> t >> a;
    for(int i = 1; i <= t; i++){
        cin >> s;  
        for(int j = 1; j <= a; j++){
            b[i][j] = s[j - 1];
        }
    }
    cout << down(1, 1) << "\n";
}
