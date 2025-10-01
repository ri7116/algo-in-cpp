#include<bits/stdc++.h>
using namespace std;

int arr[19][19];
int dy[4]={0, 1, 1, -1};
int dx[4]={1, 1, 0, 1};

void dfs(int y, int x, int direct, int cnt, int st_y, int st_x, int color){
    if(cnt == 5){
        // 6목 체크 (라인의 끝 부분)
        int ny = y + dy[direct];
        int nx = x + dx[direct];
        if(ny >= 0 && ny < 19 && nx >= 0 && nx < 19 && arr[ny][nx] == color) return;
        
        cout << color << endl;
        cout << st_y + 1 << " " << st_x + 1 << endl;
        
        exit(0); 
    }

    int ny = y + dy[direct];
    int nx = x + dx[direct];
    if(ny >= 0 && ny < 19 && nx >= 0 && nx < 19 && arr[ny][nx] == color) {
        dfs(ny, nx, direct, cnt + 1, st_y, st_x, color);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if(arr[i][j] != 0) {
                for(int k = 0; k < 4; k++){
                    // 6목 체크 (라인의 시작 부분) - 이 로직은 이제 완벽합니다!
                    int prev_y = i - dy[k];
                    int prev_x = j - dx[k];
                    if (prev_y >= 0 && prev_y < 19 && prev_x >= 0 && prev_x < 19 && arr[prev_y][prev_x] == arr[i][j]) continue;
                    
                    dfs(i, j, k, 1, i, j, arr[i][j]);
                }
            }
        }
    }
    
    cout << 0 << endl;
    
    return 0;
}