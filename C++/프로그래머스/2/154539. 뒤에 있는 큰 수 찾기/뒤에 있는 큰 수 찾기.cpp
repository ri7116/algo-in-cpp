#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> st;
    answer[numbers.size()-1]=-1;
    st.push(numbers[numbers.size()-1]);
    
    for(int i=numbers.size()-2;i>=0;i--){
        while(!st.empty()){
            if(st.top()>numbers[i]){
                answer[i]=st.top();
                st.push(numbers[i]);
                break;
            }
            else{
                st.pop();
            }
        }
        if(st.empty()){
            answer[i]=-1;
            st.push(numbers[i]);
        }
    }
    return answer;
}