#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    answer[prices.size()-1]=0;
    for(int i=0;i<prices.size()-1;i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() and prices[i]<prices[st.top()]){
                answer[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        int tmp=st.top();
        st.pop();
        answer[tmp]=prices.size()-1-tmp;
    }
    return answer;
}