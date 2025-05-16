function solution(dartResult) {
    let answer = 0;
    let tmp = [];
    let idx = -1;

    // 각 문자 순회
    for (let i = 0; i < dartResult.length; i++) {
        const ch = dartResult[i];

        if (ch === "*") {
            // 스타상: 해당 점수와 이전 점수를 2배
            tmp[idx] *= 2;
            if (idx - 1 >= 0) tmp[idx - 1] *= 2;
        }
        else if (ch === "#") {
            // 아차상: 해당 점수를 음수로 변환
            tmp[idx] *= -1;
        }
        else if (ch === "S") {
            // Single → 1제곱: 변화 없음
        }
        else if (ch === "D") {
            // Double → 2제곱
            tmp[idx] = tmp[idx] * tmp[idx];
        }
        else if (ch === "T") {
            // Triple → 3제곱
            tmp[idx] = tmp[idx] * tmp[idx] * tmp[idx];
        }
        else {
            // 숫자 처리: 10일 경우 한 번에 푸시
            if (ch === "1" && dartResult[i + 1] === "0") {
                tmp.push(10);
                idx++;
                i++;  // '0' 스킵
            } else {
                tmp.push(parseInt(ch, 10));  // 문자 → 숫자
                idx++;
            }
        }
    }

    // 총점 합산
    for (let j = 0; j < tmp.length; j++) {
        answer += tmp[j];
    }
    return answer;
}