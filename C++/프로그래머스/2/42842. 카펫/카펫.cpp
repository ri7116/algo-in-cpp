#include <string>
#include <vector>

using namespace std;
int n,m;
vector<int> solution(int brown, int yellow) {
    for(int i=0;i<2500;i++){
        for(int j=0;j<10000;j++){
            if(yellow==(i-2)*(j-2) and brown==2*i+(j-2)*2) {
                m=i;
                n=j;
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(m);
    answer.push_back(n);
    return answer;
}