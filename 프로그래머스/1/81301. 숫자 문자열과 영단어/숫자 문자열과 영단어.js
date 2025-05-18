function solution(s) {
    var answer = 0;
    // for(let i;i<s.size();i++){
    //     if(s[i]=='z' && s[i+1]=='e'&& s[i+2]=='r'&& s[i+3]=='o'){
    //         //slice(시작위치, 종료위치)
    //         //substr(시작위치, 갯수) substr(시작위치) 
    //         s=s.slice(0,i-1)+s.substr(i+4);
    //     }
    //     if(s[i]=='o'&& s[i+1]=='n'&& s[i+2]=='e')
    //     if(s[i]=='t'&& s[i+1]=='w'&& s[i+2]=='o')
    //     if(s[i]=='t'&& s[i+1]=='h'&& s[i+2]=='r'&& s[i+3]=='e')
    //     if(s[i]=='f'&& s[i+1]=='o'&& s[i+2]=='u'&& s[i+3]=='r')
    //     if(s[i]=='f'&& s[i+1]=='i'&& s[i+2]=='v'&& s[i+3]=='e')
    //     if(s[i]=='s'&& s[i+1]=='i'&& s[i+2]=='x')
    //     if(s[i]=='s'&& s[i+1]=='e'&& s[i+2]=='v')
    //     if(s[i]=='e'&& s[i+1]=='i'&& s[i+2]=='g')
    //     if(s[i]=='n'&& s[i+1]=='i'&& s[i+2]=='n'&& s[i+3]=='e')
    // }
    let str= "qwertzero5"
    str=str.slice(0,4)+str.substr(4+5);
    console.log(str);
    return answer;
}