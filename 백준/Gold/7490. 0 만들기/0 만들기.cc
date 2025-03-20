#include <bits/stdc++.h>
using namespace std;
int n,k;
char arr[14];
int num[10];
int tmp[10];
char tmp_[10];
vector <string> v;
//중간간


//중복 순열
void fuc(int depth){
    if(depth==n-1){
        // //==========디버깅
        // for(int i=0;i<n-1;i++){
        //     cout<<num[i]<<arr[i];
        //  }
        //  cout<<num[n-1];
        //  cout<<endl;
        // //============디버깅
        for(int i=0;i<n-1;i++){
            tmp_[i]=arr[i];
        }
        
         for(int i=0;i<n;i++){
            tmp[i]=i+1;
        }
        //=============
        for(int i=0;i<n-1;i++){
            if(arr[i]==' '){
                tmp[i]=(num[i]*10+num[i+1]);
                arr[i]='+';
                tmp[i+1]=0;
                //!주의
                if(i>=1 and tmp[i-1]%10==tmp[i]/10){
                    
                    //부호를 어떻게?
                    tmp[i]=tmp[i-1]*10+tmp[i]%10;
                    tmp[i-1]=0;
                }
                //i++;
            }
        }
        //디버깅
        //  for(int i=0;i<=n-1;i++){
        //      cout<<tmp[i]<<arr[i];
        //  }
        //cout<<endl;
        //디버깅깅
        int cnt=tmp[0];
        //cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
        //cout<<tmp_[0]<<" "<<tmp_[1]<<" "<<tmp_[2]<<endl;
        for(int i=0;i<n-1;i++){
            if(arr[i]=='+') cnt+=tmp[i+1];
            if(arr[i]=='-') cnt-=tmp[i+1];
        }
        // cout<<cnt<<endl;
        //정답부분
        string str="";
        if(cnt==0){
            // for(int i=0;i<=n-1;i++){
            //     str+=to_string(num[i]);
            //     str+=string(1,tmp_[i]);//char[] to string
            // }

            str += to_string(num[0]);
            for (int i = 0; i < n - 1; i++) {
                str += string(1, tmp_[i]); // i번째 연산자
                str += to_string(num[i + 1]);
            }
            //cout<<"str :"<<str;
            //cout<<endl;
            v.push_back(str);
        }
        

        //원복
        for(int i=0;i<n-1;i++){
            arr[i]=tmp_[i];
        }

        
        return;
    }

    for(int i=0;i<3;i++){
        if(i==0) arr[depth]=' ';
        if(i==1) arr[depth]='+';
        if(i==2) arr[depth]='-';
        fuc(depth+1);
    }
}

int main(){
    cin>>k;
    while(k--){
    cin>>n;
    for(int i=0;i<n;i++){
        num[i]=i+1;
        //cout<<num[i];
        tmp[i]=i+1;
    }
    fuc(0);
    sort(v.begin(),v.end());
    for(auto a: v){
        cout<<a<<endl;
    }
    cout<<endl;
    v.clear();
    }


    //왜 안되는지 있다가 찾아보기(0~9까지 밖에 없으니)
    // cout<<endl;
    // cout<<num[2]<<endl;
    // cout<<(num[1]-'0')*10<<endl;
    // cout<<(num[2]-'0')<<endl;
    // num[1]=(((num[1]-'0')*10)+(num[2]-'0'))+'0';
    // cout<<"num[i] : "<<num[1];


}