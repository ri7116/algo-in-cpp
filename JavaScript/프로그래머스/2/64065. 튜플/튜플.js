function solution(s) {
    // 1. 중괄호를 대괄호로 바꿔 "[[2],[2,1],[2,1,3],[2,1,3,4]]" 형태로 변환
    let tuple = s.replaceAll("}", "]").replaceAll("{", "[");

    // 2. JSON 파싱: [문자열 → 2차원 배열]로 변환
    tuple = JSON.parse(tuple);
    
    console.log(tuple);
    // 3. 내부 배열 길이 기준 오름차순 정렬
    tuple.sort((a, b) => a.length - b.length);

    // 4. Set에 순서대로 추가하며 중복 제거
    const list = new Set();
    for (let i = 0; i < tuple.length; i++) {
        for (let j = 0; j < tuple[i].length; j++) {
            list.add(tuple[i][j]);
        }
    }

    // 5. [Set => 배열]로 변환해 반환
    return Array.from(list);
}
