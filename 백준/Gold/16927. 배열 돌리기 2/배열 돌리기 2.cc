#include<bits/stdc++.h>
using namespace std;

int height;//새로
int width;//가로

int board[304][304];//정답 배열
int rotated_board[304][304];//회전 과정을 담을 배열

int rotate_count;

int input_value;

// 안과 바깥의 횟수 차이는 계산이 가능한데 어떻게 구현할 것인가?
// 
void rotate(){
    int x_start = 0;
    int x_end = width - 1;
    int y_start = 0;
    int y_end = height - 1;
    
    for (int k = 0; k < min(height, width) / 2; k++) {
        if ( k != 0) {
            x_start++;
            x_end--;
            y_start++;
            y_end--;
        }
        
        int result_count = rotate_count % (((x_end-x_start+1) + (y_end-y_start+1)) * 2 - 4); // 한바퀴 돌면 같으니까 모듈러 연산(문제 조건 1 ≤ R ≤ 10^9을 해소) => 최적화 2 
    
        //여기에서 너무 많은 배열 접근이 발생하는 거 같음 => 최적화  1
        for(int k = 0; k < result_count; k++){
            for(int i = y_start; i < y_end; i++){
                rotated_board[i+1][x_start] = board[i][x_start];
            }
            for(int i = y_start; i < x_end; i++){
                rotated_board[y_end][i+1] = board[y_end][i];
            }
            for(int i = y_start + 1; i <= y_end; i++){
                rotated_board[i-1][x_end] = board[i][x_end];
            }
            for(int i = x_start + 1; i <= x_end; i++){
                rotated_board[y_start][i-1] = board[y_start][i];
            }

            // for (int i = y_start; i <= y_end; i++) {
            //     for (int j = x_start; j <= x_end; j++) {
            //         if( j == x_start and i != y_end) rotated_board[i+1][j] = board[i][j];
            //         if( i == y_end and j != x_end) rotated_board[i][j+1] = board[i][j];
            //         if( j == x_end and i != y_start) rotated_board[i-1][j] = board[i][j];
            //         if( i == y_start and j != x_start) rotated_board[i][j-1] = board[i][j];
            //     }
            // }

            for (int i = 0; i < height; i++) {
                for (int j =0; j < width; j++) {
                    board[i][j] = rotated_board[i][j];
                }
            }

        }
    }
}

int main(){
    cin >> height >> width >> rotate_count;

    //rotate_count = rotate_count % ((height + width) * 2 - 2); // 한바퀴 돌면 같으니까 모듈러 연산(문제 조건 1 ≤ R ≤ 10^9을 해소) => 최적화 2 
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> input_value;
            board[i][j] = input_value;
            rotated_board[i][j] = input_value;
        }
    }

    // int x_start = 0;
    // int x_end = width - 1;
    // int y_start = 0;
    // int y_end = height - 1;

    // for (int k = 0; k < min(height, width) / 2; k++) {
    //     if ( k != 0) {
    //         x_start++;
    //         x_end--;
    //         y_start++;
    //         y_end--;
    //     }
    //     for (int i = y_start; i <= y_end; i++) {
    //         for (int j = x_start; j <= x_end; j++) {
    //             if( j == x_start and i != y_end) rotated_board[i+1][j] = board[i][j];
    //             if( i == y_end and j != x_end) rotated_board[i][j+1] = board[i][j];
    //             if( j == x_end and i != y_start) rotated_board[i-1][j] = board[i][j];
    //             if( i == y_start and j != x_start) rotated_board[i][j-1] = board[i][j];
    //         }
    //     }

    //     for (int i = 0; i < height; i++) {
    //         for (int j =0; j < width; j++) {
    //             board[i][j] = rotated_board[i][j];
    //         }
    //     }
    // }

    rotate();

    for (int i = 0; i < height; i++) {
        for (int j =0; j < width; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}



