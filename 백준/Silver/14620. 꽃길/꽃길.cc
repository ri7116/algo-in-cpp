// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int arr[1000000];
// int visited[1000000];
// int ans=987654321;
// void fuc(int depth,int cur){
//     if(depth==3){
//         int sum_=0;
//         for(int i=0;i<n*n;i++){
//             if(visited[i]==1) {
//                 sum_+=arr[i];
//                 //cout<<i<<" "; 
//             }
//         }
//         cout<<endl;
//         ans=min(ans, sum_);
//         return;
//     }
//     for(int i=cur;i<n*n;i++){
//         if(visited[i]) continue;
        
//         if(i/n==0 and i%n==0){
//             visited[i]=1;
//             visited[i+1]=1;
//             visited[i+n]=1;
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i+1]=0;
//             visited[i+n]=0;
//         }

//         else if(i/n==0 and i%n==n-1){
//             visited[i]=1;
//             visited[i-1]=1;
//             visited[i+n]=1;
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i-1]=0;
//             visited[i+n]=0;
//         }

//         else if(i/n==n-1 and i%n==0){
//             visited[i]=1;
//             visited[i+1]=1;
//             visited[i-n]=1;
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i+1]=0;
//             visited[i-n]=0;
//         }

//         else if(i/n==n-1 and i%n==n-1){
//             visited[i]=1;
//             visited[i-1]=1;
//             visited[i-n]=1;
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i-1]=0;
//             visited[i-n]=0;
//         }

//         else if(i/n==0){
//             visited[i]=1;
//             visited[i-1]=1;
//             visited[i+1]=1;
//             visited[i+n]=1;
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i-1]=0;
//             visited[i+1]=0;
//             visited[i+n]=0;
//         }        
//         else if(i/n==n-1){
//             visited[i]=1;
//             visited[i-1]=1;
//             visited[i+1]=1;
//             visited[i-n]=1;    
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i-1]=0;
//             visited[i+1]=0;
//             visited[i-n]=0;
//         }        
//         else if(i%n==0){
//             visited[i]=1;
//             visited[i+1]=1;
//             visited[i+n]=1;
//             visited[i-n]=1;    
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i+1]=0;
//             visited[i+n]=0;
//             visited[i-n]=0;
//         }        
//         else if(i%n==n-1){
//             visited[i]=1;
//             visited[i-1]=1;
//             visited[i+n]=1;
//             visited[i-n]=1;    
//             fuc(depth+1,i+1);
//             visited[i]=0;
//             visited[i-1]=0;
//             visited[i+n]=0;
//             visited[i-n]=0;
//         }
//         else{
//         visited[i]=1;
//         visited[i-1]=1;
//         visited[i+1]=1;
//         visited[i+n]=1;
//         visited[i-n]=1;
//         fuc(depth+1,i+1);
//         visited[i]=0;
//         visited[i-1]=0;
//         visited[i+1]=0;
//         visited[i+n]=0;
//         visited[i-n]=0;
//         }
//     }
// }




// int main(){
//     cin>>n;
//     for(int i=0;i<n*n;i++){
//         cin>>arr[i];
//     }
//     fuc(0,0);
//     cout<<ans;
// }
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define INF 2e9

using namespace std;
int N;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,1,0,-1 };
int Answer = INF;

void dfs(int Depth) {
	if (Depth == 3) {
        int Sum=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Visited[i][j]) Sum+=MAP[i][j];
            }
        }
		Answer = min(Answer,Sum);
		return;
	}

	for (int i = 1; i < (N - 1); i++) {
		for (int j = 1; j < (N - 1); j++) {
			if (!Visited[i][j] && !Visited[i - 1][j] && !Visited[i][j - 1] && !Visited[i + 1][j] && !Visited[i][j + 1]) {
				Visited[i][j] = true;
				Visited[i - 1][j] = true;
				Visited[i][j - 1] = true;
				Visited[i + 1][j] = true;
				Visited[i][j + 1] = true;
				dfs(Depth + 1);
				Visited[i][j + 1] = false;
				Visited[i + 1][j] = false;
				Visited[i][j - 1] = false;
				Visited[i - 1][j] = false;
				Visited[i][j] = false;
			}
		}
	}
}

void settings() {
	dfs(0);
}

void print_Answer() {
	cout << Answer << "\n";
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	settings();
	print_Answer();

	return 0;
}
//1. 조합은 보통 인자가 2개인데 인자가 1개인 이유는 visited 배열을 쓰기 때문임