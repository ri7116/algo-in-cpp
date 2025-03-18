#include <string>
#include <vector>

using namespace std;
int ans;
void cnt(int n){
    if(n==1) return;
    if(n==2){
        ans++;
        return;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return;
    }
    ans++;
    return;
}

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        cnt(i);
    }
    
    answer=ans;
    return answer;
}