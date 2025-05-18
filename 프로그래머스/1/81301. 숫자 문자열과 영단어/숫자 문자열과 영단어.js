function solution(s) {
    // 0~9에 대응하는 영어 단어 배열
    const numbers = [
        "zero","one","two","three","four",
        "five","six","seven","eight","nine"
    ];

    // 치환 대상 문자열
    let answer = s;

    // 영어 단어를 숫자 문자로 차례로 바꾼다
    for (let i = 0; i < numbers.length; i++) {
        answer = answer.split(numbers[i]).join(i);
    }

    // 치환이 끝난 문자열을 숫자 타입으로 변환하여 반환
    return Number(answer);
}
