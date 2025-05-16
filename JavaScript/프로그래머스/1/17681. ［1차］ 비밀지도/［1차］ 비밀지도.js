function solution(n, arr1, arr2) {
    var answer = [];
    //둘 중 하나라도 벽이면 전체는 벽
    //모두 공백인 부분이어야 공백
    for(let i=0;i<n;i++){
        let tmp=[];
        let str1=arr1[i].toString(2).padStart(n,"0");
        let str2=arr2[i].toString(2).padStart(n,"0");
        //console.log(str1);
        //console.log(str2);
        for(let j=0;j<n;j++){
            if(str1[j]==0 && str2[j]==0) tmp.push(" ");
            else tmp.push("#");
        }
        let realPush=tmp.join("");
        answer.push(realPush);        
    }
    return answer;
}
//10진수 -> 2진수 toString(2)
//자릿수 맞추기 위해서 padStart로 만든다.