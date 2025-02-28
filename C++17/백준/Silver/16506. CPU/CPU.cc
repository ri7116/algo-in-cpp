#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    string str;
    int D, A, B;
    for(int i=0; i<n; i++){
        cin >> str >> D >> A >> B;
        
        if(str=="ADD")
            cout << "00000";
        else if(str=="ADDC")
            cout << "00001";     
        else if(str=="SUB")
            cout << "00010";  
        else if(str=="SUBC")
            cout << "00011"; 
        else if(str=="MOV")
            cout << "00100"; 
        else if(str=="MOVC")
            cout << "00101"; 
        else if(str=="AND")
            cout << "00110"; 
        else if(str=="ANDC")
            cout << "00111"; 
        else if(str=="OR")
            cout << "01000"; 
        else if(str=="ORC")
            cout << "01001"; 
        else if(str=="NOT")
            cout << "01010"; 
        else if(str=="MULT")
            cout << "01100"; 
        else if(str=="MULTC")
            cout << "01101"; 
        else if(str=="LSFTL")
            cout << "01110"; 
        else if(str=="LSFTLC")
            cout << "01111"; 
        else if(str=="LSFTR")
            cout << "10000"; 
        else if(str=="LSFTRC")
            cout << "10001"; 
        else if(str=="ASFTR")
            cout << "10010"; 
        else if(str=="ASFTRC")
            cout << "10011"; 
        else if(str=="RL")
            cout << "10100"; 
        else if(str=="RLC")
            cout << "10101"; 
        else if(str=="RR")
            cout << "10110"; 
        else if(str=="RRC")
            cout << "10111"; 
        
        cout << "0";
        
        if(D==0)
            cout << "000";
        else if(D==1)
            cout << "001";
        else if(D==2)
            cout << "010";
        else if(D==3)
            cout << "011";
        else if(D==4)
            cout << "100";
        else if(D==5)
            cout << "101";
        else if(D==6)
            cout << "110";
        else if(D==7)
            cout << "111";
        
        if(str=="MOV" || str=="MOVC" || str=="NOT")
            cout << "000";
        else if(A==0)
            cout << "000";
        else if(A==1)
            cout << "001";
        else if(A==2)
            cout << "010";
        else if(A==3)
            cout << "011";
        else if(A==4)
            cout << "100";
        else if(A==5)
            cout << "101";
        else if(A==6)
            cout << "110";
        else if(A==7)
            cout << "111";
        
        if(str[str.length()-1] == 'C'){
            if(B==0)
                cout << "0000";
            else if(B==1)
                cout << "0001";
            else if(B==2)
                cout << "0010";
            else if(B==3)
                cout << "0011";
            else if(B==4)
                cout << "0100";
            else if(B==5)
                cout << "0101";
            else if(B==6)
                cout << "0110";
            else if(B==7)
                cout << "0111";     
            else if(B==8)
                cout << "1000";
            else if(B==9)
                cout << "1001";
            else if(B==10)
                cout << "1010";
            else if(B==11)
                cout << "1011";
            else if(B==12)
                cout << "1100";
            else if(B==13)
                cout << "1101";
            else if(B==14)
                cout << "1110";    
            else if(B==15)
                cout << "1111";   
        }
        else{
            if(B==0)
                cout << "000";
            else if(B==1)
                cout << "001";
            else if(B==2)
                cout << "010";
            else if(B==3)
                cout << "011";
            else if(B==4)
                cout << "100";
            else if(B==5)
                cout << "101";
            else if(B==6)
                cout << "110";
            else if(B==7)
                cout << "111";
            cout << "0";
        }
        
        cout << "\n";
    }
    
    return 0;
}