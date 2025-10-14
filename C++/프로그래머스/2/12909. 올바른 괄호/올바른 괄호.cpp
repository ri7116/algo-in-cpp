#include<bits/stdc++.h>
using namespace std;
stack<int> st;

bool solution(string s)
{
    bool answer = true;
    
    for(int i=0;i<s.size();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }
            }
            else st.push(s[i]);
        }
    }
    if(st.empty()) answer=true;
    else answer=false;
    return answer;
}