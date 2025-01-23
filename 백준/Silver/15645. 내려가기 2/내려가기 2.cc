  #include<bits/stdc++.h>
  using namespace std;
  int n;
  int dmax[1][3];
  int dmin[1][3];
  int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    int a,b,c;
    
    for(int i=0;i<n;i++){
      cin>>a>>b>>c;
      if(i==0){
        dmax[0][0]=a;
        dmax[0][1]=b;
        dmax[0][2]=c;
        dmin[0][0]=a;
        dmin[0][1]=b;
        dmin[0][2]=c;
        //cout<<dmax[0][0]<<dmax[0][1]<<dmax[0][2]<<endl;
        continue;
      }
      int A=dmax[0][0];
      int B=dmax[0][1];
      int C=dmax[0][2];
      int AA=dmin[0][0];
      int BB=dmin[0][1];
      int CC=dmin[0][2];
      dmax[0][0]=max(A,B)+a;
      dmax[0][1]=max(max(A,B),C)+b;
      dmax[0][2]=max(B,C)+c;
      //cout<<dmax[0][0]<<dmax[0][1]<<dmax[0][2]<<endl;
      dmin[0][0]=min(AA,BB)+a;
      dmin[0][1]=min(min(AA,BB),CC)+b;
      dmin[0][2]=min(BB,CC)+c;
    }
    cout<<max(max(dmax[0][0],dmax[0][1]),dmax[0][2])<<" "<<min(min(dmin[0][0],dmin[0][1]),dmin[0][2]);
  }
