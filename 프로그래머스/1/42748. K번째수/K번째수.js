function solution(array, commands) {
    var answer = [];
    //console.log(typeof answer);
    //console.log(array.length);
    //console.log(commands.length);
    //console.log(commands[0][0]);
    for(let i=0;i<commands.length;i++){
        //각 커맨드 적절히 처리하기
        let st=commands[i][0]-1;
        let ed=commands[i][1]-1;
        let idx=commands[i][2]-1;
        //console.log(st, ed, idx)
        
        //임시 배열로 만들기
        let tmp=[ ];
        array.map((el, idx, ar)=>{
            if(st<=idx && idx<= ed)
            tmp.push(el);
        })
        
        //정렬
        tmp.sort((a,b)=> a-b);

        console.log(tmp);
        
        //적절한 idx 정답에 넣기 
        answer.push(tmp[idx]);
    }
    return answer;
}
// 1. 자바스크립트에서 sort는 기본적으로 문자열을 기준으로 함 그래서 비교함수 (a,b)=> a-b 오름차순 b(2)-a(1) 내림차순
// 2. 배열 선언 let tmp=[ ];