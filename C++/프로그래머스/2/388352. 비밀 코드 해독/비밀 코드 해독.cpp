#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    //완탐 안되나? 10^5
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n;b++){
            for(int c=b+1;c<=n;c++){
                for(int d=c+1;d<=n;d++){
                    for(int e=d+1;e<=n;e++){
                        vector<int> v;
                        v.push_back(a);
                        v.push_back(b);
                        v.push_back(c);
                        v.push_back(d);
                        v.push_back(e);
                        
                        
                        int chk=1;
                        for(int i=0;i<q.size();i++){
                            int cnt=0;
                            int arr_pointer=0;
                            int pare_pointer=0;
                            while(arr_pointer<5 and pare_pointer<5){
                                if(v[arr_pointer]==q[i][pare_pointer]){
                                    cnt++;
                                    arr_pointer++;
                                    pare_pointer++;
                                }
                                else if(v[arr_pointer]<q[i][pare_pointer]){
                                    arr_pointer++;
                                }
                                else pare_pointer++;
                            }
                            if(cnt!=ans[i]) chk=0;    
                        }
                        if(chk) {
                            for(auto aa:v){
                                //cout<<aa<<" ";
                            }
                            //cout<<endl;
                            
                            answer++;
                        }
                        
                        
                        
                        
                    }
                }
            }
        }
    }
    return answer;
}
// 서로 다른 5개의 정수!
// 완탐 + 투포인터