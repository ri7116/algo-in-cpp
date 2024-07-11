#include<bits/stdc++.h>
using namespace std;
int D[1000004];
int n;
vector <int> v;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    D[1]=0;
    D[2]=1;
    D[3]=1;
    for(int i=4;i<=n;i++){
        if(i%2==0 and i%3==0) D[i]=min(D[i-1],min(D[i/2],D[i/3]))+1;
        else if(i%2==0 and i%3!=0)  D[i]=min(D[i-1],D[i/2])+1;
        else if(i%2!=0 and i%3==0)  D[i]=min(D[i-1],D[i/3])+1;
        else D[i]=D[i-1]+1;
    }
    cout<<D[n]<<'\n';
    v.push_back(n);
    while(n!=1){
        if(n%2==0 and n%3==0){// min(D[n-1],min(D[n/2]),D[n/3]);
            if(D[n-1]<= D[n/2] and D[n-1]<=D[n/3]){
                v.push_back(n-1);
                n=n-1;
                continue;
            }

            else if(D[n/2]<= D[n-1] and D[n/2]<=D[n/3]){
                v.push_back(n/2);
                n=n/2;
                continue;
            }

            else{
                D[n/3]<= D[n-1] and D[n/3]<=D[n/2];
                v.push_back(n/3);
                n=n/3;
                continue;
            }
        
        }

        else if(n%2==0 and n%3!=0)  {
            if(D[n-1]<=D[n/2]){
                v.push_back(n-1);
                n=n-1;
                continue;
            }
            else{
                v.push_back(n/2);
                n=n/2;
                continue;
            }
        }
        else if(n%2!=0 and n%3==0) {
            if(D[n-1]<=D[n/3]){
                v.push_back(n-1);
                n=n-1;
                continue;
            }
            else{
                v.push_back(n/3);
                n=n/3;
                continue;
            }
        }
        else {
            v.push_back(n-1);
            n=n-1;
            continue;
        }
    }
    for(auto a: v){
        cout<<a<<" ";
    }

}