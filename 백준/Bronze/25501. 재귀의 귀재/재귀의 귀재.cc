#include<bits/stdc++.h>
using namespace std;
int ans=1;
int recursion(const char *s, int l, int r, int& cnt){//1. 왜 int (X) int& (O)
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else {
        cnt =cnt+1;
        //printf("cnt 증가요\n");
        return recursion(s, l+1, r-1,cnt);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1,ans);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ans=1;
        char a[1004]; //2. 왜 a는 string으로 하면 안됨?
        cin>>a;
        cout<<isPalindrome(a)<<" "<<ans<<'\n';
    }
    //cout<<isPalindrome("ABBA")<<" "<<ans<<'\n';
    //cout<<ans<<endl;
    //printf("ABC: %d\n", isPalindrome("ABC"));   // 0
}