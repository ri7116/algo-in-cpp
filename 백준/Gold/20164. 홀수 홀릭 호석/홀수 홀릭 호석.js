const fs = require("fs");
const path = require("path");

// 백준(Linux) 환경이면 /dev/stdin, 로컬 환경이면 같은 폴더의 tmp.txt를 읽음
const isLocal = process.platform !== "linux";
const filePath = isLocal ? path.join(__dirname, "tmp.txt") : "/dev/stdin";

const input = fs.readFileSync(filePath).toString().trim();

// console.log(input);

// let input = "514";
let ans_min = 1000000004;
let ans_max = -1;
//=============================== 백준 입출력은 AI가 작성함 =====================
//조합을 구현 해야함
function solution(num_str, cnt) {
  //num_str = toString(num_str); 이거 맞나?
  //재미나이야 왜 1에서 number인거야?
  //console.log(`${num_str} ${num_str.length} ${typeof num_str}`);

  let new_cnt = cnt;
  //console.log(new_cnt);
  for (let i = 0; i < num_str.length; i++) {
    if (Number(num_str[i]) % 2 != 0) {
      //console.log(num_str[i]);
      // console.log("방문이요");

      // cnt++;  재미나이야 이거 안되는거지?
      new_cnt++;
    }
  }

  //console.log(cnt);

  if (num_str.length == 1) {
    //console.log(`종료 됐구요 현재 카운트는 ${new_cnt}`);
    ans_max = Math.max(ans_max, new_cnt);
    ans_min = Math.min(ans_min, new_cnt);
    return;
  }

  //2. 2자리 수면 나눠서 합을 구하고 새로운 수로 생각한다.
  if (num_str.length == 2) {
    // console.log(num_str[0] + num_str[1]);
    let tt = Number(num_str[0]) + Number(num_str[1]);
    solution(tt + "", new_cnt);
  }

  //3. 3자리 이상이면 3등분으로 나눠서 더한다.
  if (num_str.length >= 3) {
    //nC3 이니까 재귀보다 반복분이 더 구현하기 편할듯
    for (let i = 0; i < num_str.length - 1; i++) {
      for (let j = i + 1; j < num_str.length - 1; j++) {
        // console.log(`${i} + ${j}`);
        // console.log("여기 입장");
        // console.log(num_str.slice(0, i + 1)); //(시작점, 자를곳 한칸뒤)
        // console.log(num_str.slice(i + 1, j + 1));
        // console.log(num_str.slice(j + 1, num_str.length));
        // console.log(
        //   Number(num_str.slice(0, i + 1)) +
        //     Number(num_str.slice(i + 1, j + 1)) +
        //     Number(num_str.slice(j + 1, num_str.length))
        // );
        let tt =
          Number(num_str.slice(0, i + 1)) +
          Number(num_str.slice(i + 1, j + 1)) +
          Number(num_str.slice(j + 1, num_str.length));
        solution(tt + "", new_cnt); // 재미나이야 안에 넣는건 모적ㄴ 문자열? 자바스크립트의 함수의 타입이 묵시적으로 고정인가? tt변수를 없애고 number를 안으로 넣으면 동작을 안하네?
      }
    }
  }
}

solution(input, 0);

console.log(`${ans_min} ${ans_max}`);
