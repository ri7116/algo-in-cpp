const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

solution(input);

function solution(a) {
    // 0. main 추출하기
    a = a.slice(6, -7)

    // 1. div 덩어리로 나누기
    let div_list = a.split("</div>")

    for (let i = 0; i < div_list.length-1; i++){
        //console.log("=======================================")
        let idx = 12
        
        //12부터 "가 나올때까지 타이틀 네임 받기
        while(div_list[i][idx] != '"') idx++;
        console.log("title : " + div_list[i].slice(12,idx)) 
        
        let p_list = div_list[i].split("<p>")
        //console.log(p_list)
        for(let j = 1; j < p_list.length; j++){
            let cleanText = "";
            let isTag = false;

            for(let k = 0; k < p_list[j].length; k++){
                let char = p_list[j][k];

                if(char === "<") isTag = true;

                if(char === ">") {
                    isTag = false;
                    continue;
                }

                if(!isTag) cleanText+=char;
            }
            //last 1. 양쪽 공백 없애기
            cleanText = cleanText.trim();
            //last 2. 연속된 띄어쓰기 없애기
            cleanText = cleanText.replace(/\s+/g, " ")
            console.log(cleanText);
        }
    }
}

//split
//spilce
//trim
//정규 표현식 \s + 띄어쓰기 2개 이상을 " "로 바꿔라 