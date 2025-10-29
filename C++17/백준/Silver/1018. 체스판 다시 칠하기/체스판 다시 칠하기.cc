#include<bits/stdc++.h>
using namespace std;
char MAP[54][54];
int ans=64;
char typeA[8][8]={{'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},};

char typeB[8][8]={{'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'},
                {'W','B','W','B','W','B','W','B'},
                {'B','W','B','W','B','W','B','W'}};


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            MAP[i][j]=str[j];
        }
    }
    int cnt=0;
    for(int i=0;i<=n-8;i++){
        for(int j=0;j<=m-8;j++){
            
            cnt=0;
            for(int l=i;l<i+8;l++){
                for(int m=j;m<j+8;m++){
                    if(typeA[l-i][m-j]!=MAP[l][m]) cnt++;
                }
            }
            ans=min(ans,cnt);

            cnt=0;
            for(int l=i;l<i+8;l++){
                for(int m=j;m<j+8;m++){
                    if(typeB[l-i][m-j]!=MAP[l][m]) cnt++;
                }
            }
            ans=min(ans,cnt);
        }
    }

    cout<<ans;
}