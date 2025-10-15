#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    int cur=(100-progresses[0])/speeds[0];
    if((100-progresses[0])%speeds[0]!=0) cur++;
    
    int cnt=1;
    for(int i=1;i<progresses.size();i++){
        int next=(100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0) next++;
        if(next>cur){
            ans.push_back(cnt);
            cur=next;
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    ans.push_back(cnt);
    return ans;
}