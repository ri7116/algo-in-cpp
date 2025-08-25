#include<bits/stdc++.h>
using namespace std;
deque<int> origin_dq;
int n;
int p,q;
int visited[504];
int ans;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        origin_dq.push_back(a);
    }
    
    // [수정된 부분] 모든 원소가 원형으로 역순인 엣지 케이스를 올바르게 처리합니다.
    bool is_fully_reversed = false;
    int pos_of_n = -1;
    for(int i=0; i<n; ++i) {
        if(origin_dq[i] == n) {
            pos_of_n = i;
            break;
        }
    }

    if(pos_of_n != -1) {
        is_fully_reversed = true;
        for(int i=0; i<n; ++i) {
            int current_val = origin_dq[(pos_of_n + i) % n];
            int expected_val = n - i;
            if(current_val != expected_val) {
                is_fully_reversed = false;
                break;
            }
        }
    }

    if(is_fully_reversed) {
        // k2를 1부터 n-1까지 시도하며 올바른 k1, k2 조합을 찾습니다.
        for (int k2_candidate = 1; k2_candidate < n; ++k2_candidate) {
            deque<int> temp_dq = origin_dq;
            
            // 1. k2번 오른쪽으로 밀기 (역연산)
            for (int k=0; k < k2_candidate; ++k) {
                temp_dq.push_front(temp_dq.back());
                temp_dq.pop_back();
            }

            // 2. 전체 뒤집기 (역연산)
            reverse(temp_dq.begin(), temp_dq.end());

            // 3. k1 찾기 (역연산)
            int k1_candidate = 0;
            while(temp_dq.front() != 1) {
                k1_candidate++;
                temp_dq.push_front(temp_dq.back());
                temp_dq.pop_back();
            }

            if (k1_candidate >= 1) {
                cout << k1_candidate << endl;
                cout << 1 << " " << n << endl;
                cout << k2_candidate << endl;
                return 0;
            }
        }
    }


    for(int i=1;i<n;i++){
        deque<int> new_dq=origin_dq;
        if(ans==1) return 0;
        //i번 k 오른쪽 연산
        int b=i;
        while(b--){
            int tmp=new_dq.back();
            new_dq.pop_back();
            new_dq.push_front(tmp);
        }
        for(int j=0;j<504;j++) visited[j]=0;


        //1.
        for(int j=0; j<n; j++){
            // 일반적인 내림차순 관계 (예: 5 -> 4)
            if (new_dq[(n+j-1)%n] - new_dq[j] == 1) {
                visited[(n+j-1)%n] = visited[j] = 1;
            }
            // 원형으로 이어지는 내림차순 관계 (예: 1 -> n)
            if (new_dq[(n+j-1)%n] == 1 && new_dq[j] == n) {
                visited[(n+j-1)%n] = visited[j] = 1;
            }
        }
        // //1차이가 아니면 역순이 잇는거
        // for(int j=0;j<n-1;j++){
        //     if(new_dq[j+1]-new_dq[j]!=1) visited[j]=1;
        // }
        // if(new_dq[n-1]-new_dq[n-2]!=1) visited[n]=1;

        //2. 
        int chk1=0;
        int chk2=0;
        int chk3=0;
        for(int j=0;j<n;j++){
            if(visited[j]==1) chk1=1;
            if(chk1==1 and visited[j]==0) chk2=1;
            if(chk2==1 and visited[j]==1) chk3=1;//101인경우 즉 연속된 뒤집기 경우가 나오지 않는 경우
        }
        if(chk3==1) {
          //  cout<<"101 존재\n";
            continue;
        }

        // 오류 체크용 주석
        //cout<<"이상x\n";
        // for(int j=0;j<n;j++){
        //     cout<<visited[j];
        // }
        // cout<<endl;
        //오류 체크용 주석

        int chk_p=0;
        for(int j=0;j<n;j++){
            if(visited[j]==1 and chk_p==0) {
                p=j;
                chk_p=1;
            }
            if(chk_p==1 and visited[j]==0) {
                q=j-1;
			break;
		}
	}
        if(visited[n-1]==1) q=n-1;
        //cout<<p <<" : " << q <<endl;



        // for(auto a: new_dq){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        
        // [정리된 부분] 중복된 p, q 찾기 로직을 삭제했습니다.
        for(int j=0;j<(q-p+1)/2;j++){
            swap(new_dq[p+j],new_dq[q-j]);
        }

        


        //3. 
        int cnt=0;
        while(new_dq[0]!=1){
            cnt++;
            int tmp=new_dq.back();
            new_dq.pop_back();
            new_dq.push_front(tmp);           
        }
        if(cnt==0) continue;

        // for(auto a: new_dq){
        //     cout<<a<<" ";
        // }
        // cout<<endl;

        cout<<cnt<<endl;
        cout<<p+1<<" "<<q+1<<endl;
        cout<<i;
        
        ans=1;
    }

}
// 1. k1, k2가 0인 경우도 가능함
// 2. 문제 풀이에 0based를 했지만 1based가 문제에서 요구하는 답