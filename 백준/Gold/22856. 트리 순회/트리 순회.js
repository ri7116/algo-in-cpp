const fs = require("fs");
const path = require("path");

// 백준(Linux) 환경이면 /dev/stdin, 로컬 환경이면 같은 폴더의 tmp.txt를 읽음
const isLocal = process.platform !== "linux";
const filePath = isLocal ? path.join(__dirname, "tmp.txt") : "/dev/stdin";

const input = fs.readFileSync(filePath).toString().trim().split("\n");

// 1. n 파싱
let n = Number(input[0]);

// 2. arr 파싱 (사용자님이 작성한 데이터 포맷 [[1,2,3], ...] 에 맞춤)
let arr = [];
for (let i = 1; i <= n; i++) {
  // "1 2 3" 문자열을 -> [1, 2, 3] 숫자 배열로 바꿔서 arr에 추가
  arr.push(input[i].split(" ").map(Number));
}

//================================ 위까지의 코드는 AI가 작성함 =====================

//let tree = new Array(100004).fill([]); 이거 안되네?? 2차원 배열 생성의 잘못된 예
let tree = Array.from(Array(100004), () => []); // 2차원 배열 생성

//console.log(tree)

let visited_cnt = 0;
let cnt = 0;
let isAns = false;
function dfs(cur) {
  if (tree[cur][0] != -1) {
    //console.log(tree[cur][0] + "로 이동");
    cnt++;

    if (!isAns && visited_cnt == n) {
      console.log(cnt);
      isAns = true;
    }

    dfs(tree[cur][0]);
    //console.log(tree[cur][0] + "에서 되돌아옴");
    cnt++;
  }

  //console.log(cur);
  //중위 순회에서의 체크를 하지 않았음
  visited_cnt++;
  //console.log(cur + "방문증가");

  if (!isAns && visited_cnt == n) {
    console.log(cnt);
    isAns = true;
  }

  if (tree[cur][1] != -1) {
    //console.log(tree[cur][1] + "로 이동");

    cnt++;

    if (!isAns && visited_cnt == n) {
      console.log(cnt);
      isAns = true;
    }

    dfs(tree[cur][1]);
    //console.log(tree[cur][1] + "에서 되돌아옴");
    cnt++;
  }
}

for (let i = 0; i < arr.length; i++) {
  //  console.log(arr[i][0])
  //  console.log(arr[i][1])
  //  console.log(arr[i][2])
  tree[arr[i][0]].push(arr[i][1]);
  tree[arr[i][0]].push(arr[i][2]);
}

// console.log(tree)

dfs(1);
//console.log(cnt)

//중간 노드가 진짜 순회 방문 했을 때의 index 값임
