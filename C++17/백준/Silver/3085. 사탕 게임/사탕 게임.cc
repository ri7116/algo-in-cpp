#include<bits/stdc++.h>
using namespace std;
int n;
char arr[54][54];
char arr2[54][54];
int ans;

int main(){
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            arr[i][j]=str[j];
            arr2[i][j]=str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=arr[i+1][j]){
                if(i+1==n) continue;//범위초과 넘어가
                swap(arr[i][j],arr[i+1][j]);
                int _max=0;
                for(int k=0;k<n;k++){
                    int cur=0;
                    for(int r=0;r<n;r++){
                        if(r==0)cur++;

                        else{
                            if(arr[k][r-1]!=arr[k][r]){
                                if(cur>_max) _max=cur;
                                cur=1;
                            }
                            else cur++;
                        }
                    }
                    if(cur>_max) _max=cur;
                }

                for(int k=0;k<n;k++){
                    int cur=0;
                    for(int r=0;r<n;r++){
                        if(r==0) r++;
                        else{
                            if(arr[r-1][k]!=arr[r][k]){
                                if(cur>_max) _max=cur;
                                cur=1;
                            }
                            else cur++;
                        }
                    }
                    if(cur>_max) _max=cur;
                }
                if(_max>ans) ans=_max;
                swap(arr[i][j],arr[i+1][j]);
            }

            if(arr[i][j]!=arr[i][j+1]){
                if(j+1==n) continue;// 범위 초과 넘어가
                swap(arr[i][j],arr[i][j+1]);                int _max=0;
                for(int k=0;k<n;k++){
                    int cur=0;
                    for(int r=0;r<n;r++){
                        if(r==0) cur++;
                        else{
                            if(arr[k][r-1]!=arr[k][r]){
                                if(cur>_max) _max=cur;
                                cur=1;
                            }
                            else cur++;
                        }
                    }
                    if(cur>_max) _max=cur;
                }

                for(int k=0;k<n;k++){
                    int cur=0;
                    for(int r=0;r<n;r++){
                        if(r==0) cur++;
                        else{
                            if(arr[r-1][k]!=arr[r][k]){
                                if(cur>_max) _max=cur;
                                cur=1;
                            }
                            else cur++;
                        }
                    }
                    if(cur>_max) _max=cur;
                }
                if(_max>ans) ans=_max;
                swap(arr[i][j],arr[i][j+1]);
            }
        }
    }
    cout<<ans;
}
//가장 긴 '연속 부분'