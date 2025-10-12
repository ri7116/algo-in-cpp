#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int ans = -1;
    
    int st=0;
    int ed=distance+4;
    sort(rocks.begin(),rocks.end());
    
    while(st<=ed){
        int mid =(st+ed)/2;
        //cout<<mid<<"미드는 이거임"<<endl;
        
        int st_distance=0;
        int cnt=0;
        int chk=0;
        int isNo=0;
        
        for(int i=0;i<rocks.size();i++){
            if(chk==1){//1. 최소 거리를 만족 못하는 중이야
                if(rocks[i]-st_distance>=mid){//1-1. 이 지점에서 최소 거리를 만족했네
                    st_distance=rocks[i];
                    chk=0;
                    //cout<<i<<"만족\n";
                }
                else{//1-2. 이 지점에서도 최소 거리를 만족하지 못했네
                    cnt++;
                    chk=1;
                    //cout<<i<<" 제거\n";                        
                }
            }
            else{//2. 일단 최소 거리 만족 하는지 다음 단게를 보자
                if(rocks[i]-st_distance<mid){//2-1. 최소 거리 만족 X
                    cnt++;
                    chk=1;
                    //cout<<i<<" 제거\n";
                }
                else{//2-2. 최소 거리 만족
                    st_distance=rocks[i];
                    chk=0;
                }
            }
        }
        
        if(distance-st_distance<mid) cnt++; // 최소 거리를 만족하지 못하면 그냥 제거 횟수를 1 늘린다

        // 이제 '최종 제거 횟수(cnt)' 하나만으로 판단!
        if (cnt > n) {
            // mid를 만족시키기 위해 너무 많은 돌을 제거해야 하므로, mid는 불가능한 값
            // 최소 거리를 줄여야 함
            ed = mid - 1;
        } else {
            // n개 이하의 돌을 제거해서 mid를 만족시켰으므로, mid는 가능한 값
            // 이 값을 정답 후보로 저장하고, 최소 거리를 더 늘려본다
            ans = max(ans, mid);
            st = mid + 1;
        }
        
        // if(cnt>n and !isNo){//최소 간격이 크면(가능하면 더 줄여볼까?)
        //     ed=mid-1;
        //     //cout<<"너무 많이 지웠네\n";
        // }
        // else if(cnt==n and !isNo){//최소 간격을 늘려볼까?
        //     ans=max(ans,mid);
        //     st=mid+1;
        //     //cout<<"적절히 지웠네\n";//그러면 간격을 늘려봐서 최적화 지점을 찾아보자
        // }
        // else if(cnt<n and !isNo){
        //     st=mid+1;
        //     //cout<<"너무 적게 지웠네\n";//최소 간격을 늘려봐서 cnt 올려보자
        // }
        // else if(cnt>n and isNo){ //간격 무조건 늘려야함
        //     ed=mid-1;
        // }
        // else if(cnt==n and isNo){//간격 무조건 늘려야함
        //     ed=mid-1;
        // }
        // else if(cnt<n and isNo){//간격 무조건 늘려야함
        //     ed=mid-1;
        // }
    }
    return ans;
}