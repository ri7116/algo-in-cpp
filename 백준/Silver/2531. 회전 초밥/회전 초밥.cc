    #include<bits/stdc++.h>
    using namespace std;
    
    int main(){
      int n,d,k,c;
      cin>>n>>d>>k>>c;

      vector<int> node(n);
      for(int i=0;i<n;i++) cin>>node[i];

      vector<int> eat(d+1,0);

      int ans=0, cnt=0;

      for(int i=0;i<k;i++){
        if(!eat[node[i]]) cnt++;
        eat[node[i]]++;
      }
      ans= cnt+ (eat[c] ? 0 : 1);

      for(int i=0;i<n;i++){
        eat[node[i]]--;
        if(!eat[node[i]])cnt--;//슬라이딩 앞
        if(!eat[node[(i+k)%n]])cnt++; //슬라이딩 뒤
        eat[node[(i+k)%n]]++;

        ans= max(ans, cnt+ (eat[c] ? 0 : 1));
      }
      cout<<ans;
    }
    //답지 보고 공부함
    //길이가 고정이므로 슬라이딩 윈도우 