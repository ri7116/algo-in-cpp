#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt=0;
    answer.push_back(number[0]);
    for(int i=1;i<number.size();i++){
        while(!answer.empty() and cnt<k and answer[answer.size()-1]<number[i]){
                answer.pop_back();
                cnt++;
        }
        answer.push_back(number[i]);
    }
    while(cnt < k){
        answer.pop_back();//엣지 케이스
        cnt++;
    }
    return answer;
}
//스택을 이용한 풀이