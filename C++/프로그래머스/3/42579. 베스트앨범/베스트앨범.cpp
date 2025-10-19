#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> mp;
    int genres_num=0;
    for(int i=0;i<genres.size();i++){
        if(mp.find(genres[i])==mp.end()){
            genres_num++;
            mp[genres[i]]+=plays[i];
        }
        else mp[genres[i]]+=plays[i];
    }
    
    
    
    
    for(int j=0;j<genres_num;j++){
        //장르 찾기
        int cnt=-1;
        string max_string;
        for(auto a: mp){
            if(cnt<a.second) {
                max_string=a.first;
                cnt=a.second;
            }
        }

        //곡 집어 넣기 1
        cnt=-1;
        int max_idx=-1;
        for(int i=0;i<genres.size();i++){
            if(genres[i]==max_string){
                if(plays[i]>cnt){
                    cnt=plays[i];
                    max_idx=i;
                }
            }
        }
        if(max_idx!=-1 and plays[max_idx] != 0) answer.push_back(max_idx);//엣지 케이스 재생횟수 0으로 초기화 한 건에 대하여.
        if(max_idx!=-1) plays[max_idx]=0;
        //곡 집어 넣기 2
        cnt=-1;
        max_idx=-1;
        for(int i=0;i<genres.size();i++){
            if(genres[i]==max_string){
                if(plays[i]>cnt){
                    cnt=plays[i];
                    max_idx=i;
                }
            }
        }
        if(max_idx!=-1 and plays[max_idx] != 0) answer.push_back(max_idx);

        //방금 장르 삭제
        mp[max_string]=0;
    }
    
    return answer;
}