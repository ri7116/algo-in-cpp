#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
char arr[7];
int visited[7];
vector <int> v;

int sosu(int n){
    if(n < 2) return 0; // 0과 1은 소수가 아님!! 나중에 지워보자
    for (int i = 2; i * i <= n; i++){ // 루트 n까지만 검사
        if (n % i == 0) return 0;
    }
    return 1; //소수
}



//나중에 ans &없애보자 
void fuc(int depth,int cur,int n, int size, int& ans,string str){
    if(depth==n){
        //디버깅
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        //////
        
        
        //맨앞이 0인지?
        if(n!=0 and arr[0]=='0') return;
        //소수인지?
        string temp="";
        for(int i=0;i<n;i++){
            temp+=arr[i];
        }
        int a=stoi(temp);
        if(!sosu(a)) return;
        v.push_back(a);
        cout<<a<<"넣겠습니다!\n";
        ans++;
        return;
    }
    
    for(int i=0;i<size;i++){
        if(visited[i]) continue;
        arr[depth]=str[i];
        visited[i]=1;
        fuc(depth+1,i+1, n,size, ans, str);
        visited[i]=0;
    }
    
}

int solution(string numbers) {
    int answer = 0;
    //int i=0 => int i=1로 바꿈
    for(int i=1;i<=numbers.size();i++){
        fuc(0,0,i,numbers.size(),answer,numbers);
    }
    cout<<answer;
    sort(v.begin(),v.end());
    v.erase( unique(v.begin() , v.end()) , v.end());
    answer=v.size();
    for(auto a: v){
        cout<<a<<" ";
    }
    cout<<endl;
    return answer;
}