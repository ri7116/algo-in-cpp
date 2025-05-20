function solution(str1, str2) {
    // 모두 소문자로 변환
    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();
    
    const str1_arr = [];
    let intersection = 0;
    let union = 0;
    
    // str1에서 유효한 2글자 집합 추출
    for (let i = 0; i < str1.length - 1; i++) {
        if (
            str1.charCodeAt(i)   >= 97 &&
            str1.charCodeAt(i)   <= 122 &&
            str1.charCodeAt(i+1) >= 97 &&
            str1.charCodeAt(i+1) <= 122
        ) {
            str1_arr.push(str1.slice(i, i+2));
        }
    }
    union += str1_arr.length;
    
    // str2에서 교집합·합집합 계산
    for (let i = 0; i < str2.length - 1; i++) {
        if (
            str2.charCodeAt(i)   >= 97 &&
            str2.charCodeAt(i)   <= 122 &&
            str2.charCodeAt(i+1) >= 97 &&
            str2.charCodeAt(i+1) <= 122
        ) {
            const word = str2.slice(i, i+2);
            if (str1_arr.includes(word)) {
                intersection++;
                str1_arr.splice(str1_arr.indexOf(word), 1);  //(배열에서 word가 존재하는  index를 찾고,그 인덱스의 원소 1개를 제거함)
                // 배열 중간에 뭔짓(끼어 넣기, 삭제)을 하고 싶으면 splice
                // 배열을 중간을 기준으로 출력하고 싶으면 slice
            } else {
                union++;
            }
        }
    }
    
    // 분모가 0이면 최대값 반환, 아니면 비율 계산
    return union === 0
        ? 65536
        : Math.floor((intersection / union) * 65536);
}