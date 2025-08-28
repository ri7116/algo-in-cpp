// #include<bits/stdc++.h>
// using namespace std;
// struct ob{
//     int x,y,z;
// };
// deque <ob> obList;
// deque <ob> watch;
// queue <ob> q;
// int n,m,k;//조사해야 하는 칸이 모두 K이상인지?
// int w;
// int arr[1000][1000];
// int wall[1000][1000];
// int ans;
// int tmp;
// int main(){
//     cin>>n>>m>>k;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>tmp;
//             if(tmp==0) continue;
//             if(tmp==5) watch.push_back({i,j,5});
//             else obList.push_back({i,j,tmp});
//         }
//     }
//     cin>>w;
//     for(int i=0;i<w;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         wall[a][b]=c+1;
//     }
//     while(1){
//         //1. 온풍기에서 바람이 나옴
        
//         //큐에 넣기 
//         for(auto a: obList){
//             if(a.z==1) {
//                 arr[a.x][a.y+1]=5;
//                 q.push({a.x,a.y+1,5});
//             }
//             if(a.z==2) {
//                 arr[a.x][a.y-1]=5;
//                 q.push({a.x,a.y-1,5});
//             }
//             if(a.z==3) {
//                 arr[a.x-1][a.y]=5;
//                 q.push({a.x-1,a.y,5});
//             }
//             if(a.z==4) {
//                 arr[a.x+1][a.y]=5;
//                 q.push({a.x+1,a.y,5});
//             }           
//         }
//         while(q.empty()){
//             auto tt=q.front();
//             q.pop();
//             if(tt.z==1){
//                 if(!(wall[tt.x-1][tt.y]==2 or wall[tt.x][tt.y]==1)){
//                     arr[tt.x-1][tt.y+1]=tt.z-1;
//                     q.push({tt.x-1,tt.y+1,tt.z-1});
//                 }
//                 if(!wall[tt.x][tt.y]==2){
//                     arr[tt.x][tt.y+1]=tt.z-1;
//                     q.push({tt.x,tt.y+1,tt.z});
//                 }
//                 if(!(wall[tt.x+1][tt.y]==2 or wall[tt.x+1][tt.y]==1)){
//                     arr[tt.x+1][tt.y+1]=tt.z-1;
//                     q.push({tt.x+1,tt.y+1,tt.z-1});
//                 }
//             }
//             if(tt.z==2){
                
//             }
//             if(tt.z==3){

//             }
//             if(tt.z==4){

//             }
//         }



//         //4. 초콜릿 먹기
//         ans++;

//         //5. 조사하는 모든 칸이 K 이상인지 확인하기 
//         int chk=1;
//         for(auto a: watch){
//             if(arr[a.x][a.y]<k) chk=0;
//         }
//         if(chk==0) break;
//     }
//     cout<<ans;
// }
// // https://yabmoons.tistory.com/718
// // https://gooooooooooose.tistory.com/entry/boj23289
#include<bits/stdc++.h>
using namespace std;
long long d;
long long n;
long long tmp;
long long dist[104];
long long Time[104];
long long A[104];
long long B[104];
vector<int> v;


void recursive(int x){
    if(B[x]==0) return ;
    
    v.push_back(B[x]);
    
    recursive(B[x]);
}




int main(){
    cin>>d;
    cin>>n;
    for(int i=1;i<=n+1;i++){
        cin>>tmp;
        dist[i]=dist[i-1]+tmp;
        //A[i]=1000000000;
        A[i] = (long long)10e9;//(놓친부분)
    }
    for(int i=1;i<=n;i++){
        cin>>Time[i];
    }
    //!이 부분을 놓쳤음
    for (int i = 1; i <= n + 1; i++){
		if (dist[i] <= d) A[i] = Time[i];
    }
    //
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<i;j++){
            if(dist[i]-dist[j]<=d and A[i]>A[j]+Time[i]){
                B[i]=j;
                A[i]=A[j]+Time[i];
            }
        }
    }
    recursive(n+1);
    cout<<A[n+1]<<'\n';
    cout<<v.size()<<'\n';
    if(!v.empty()){
    for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
    }
}
//A[i]는 i정비소를 들렸을때까지의 최소 정비시간(i번째 정비소를 방문 한 것임)