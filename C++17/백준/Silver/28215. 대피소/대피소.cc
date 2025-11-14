#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
int dp[104];//최단거리 //나중에 0으로 초기화 하는 것을 잊지말자.
int ans=2100000000;
int n,k;


int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    if(k==1){
        for(int i=0;i<n;i++){
            fill(dp,dp+100,2100000000);

            int tmp_max=0;
            for(int r=0;r<n;r++){
                dp[r]=min(dp[r],abs(v[r].first-v[i].first+v[r].second-v[i].second));
                tmp_max=max(tmp_max,dp[r]);
            }
            ans=min(ans,tmp_max);
        }
    }
    if(k==2){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                fill(dp,dp+100,2100000000);

                int tmp_max=0;
                for(int r=0;r<n;r++){
                    dp[r]=min(dp[r],abs(v[r].first-v[i].first)+abs(v[r].second-v[i].second));
                    dp[r]=min(dp[r],abs(v[r].first-v[j].first)+abs(v[r].second-v[j].second));
                    tmp_max=max(tmp_max,dp[r]);
                }
                if(tmp_max<ans){
                    ans=min(ans,tmp_max);
                    //cout<<"여기서 갱신이요 "<<ans<<endl;
                    //cout<<i<<" : "<<j<<endl;
                }
            }
        }
    }

    if(k==3){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=j;k<n;k++){
                    fill(dp,dp+100,2100000000);

                    int tmp_max=0;
                    for(int r=0;r<n;r++){
                        dp[r]=min(dp[r],abs(v[r].first-v[i].first)+abs(v[r].second-v[i].second));
                        dp[r]=min(dp[r],abs(v[r].first-v[j].first)+abs(v[r].second-v[j].second));
                        dp[r]=min(dp[r],abs(v[r].first-v[k].first)+abs(v[r].second-v[k].second));
                        tmp_max=max(tmp_max,dp[r]);
                    }
                    ans=min(ans,tmp_max);
                }
            }
        }
    }
    cout<<ans;
}