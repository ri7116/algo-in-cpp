const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

// 입력값을 받아올 때 앞뒤 공백 제거 후 줄바꿈 문자로 나눕니다.
// /\r?\n/ 정규식은 윈도우(\r\n)와 리눅스(\n) 모두 대응합니다.
let input = fs.readFileSync(filePath).toString().trim().split(/\r?\n/);

// 폴더 구조를 저장할 Map (부모 -> 자식 폴더 리스트)
let folderGraph = new Map();
// 폴더 내 파일 정보를 저장할 Map (폴더 -> 파일 리스트)
let fileMap = new Map();

function solution(input) {
  // 첫 줄 처리 (N: 폴더 수, M: 파일 수)
  let [n, m] = input[0].split(" ").map(Number);

  // 구조 정보 파싱 (N + M 줄)
  for (let i = 1; i <= n + m; i++) {
    let [parent, name, isFolder] = input[i].split(" ");
    
    if (isFolder === "1") {
      // 폴더인 경우: folderGraph에 추가
      if (!folderGraph.has(parent)) folderGraph.set(parent, []);
      folderGraph.get(parent).push(name);
    } else {
      // 파일인 경우: fileMap에 추가
      if (!fileMap.has(parent)) fileMap.set(parent, []);
      fileMap.get(parent).push(name);
    }
  }

  // 쿼리 개수 Q
  let qIndex = n + m + 1;
  let q = +input[qIndex];

  // 결과들을 담을 배열
  const results = [];

  // 쿼리 처리
  for (let i = qIndex + 1; i <= qIndex + q; i++) {
    const queryPath = input[i];
    // 경로에서 가장 마지막 폴더 이름만 가져옵니다. 
    // 예: "main/FolderA" -> "FolderA"
    const currentFolder = queryPath.split("/").pop();

    // 이번 쿼리를 위한 집계 변수
    // Set을 사용하여 파일 종류(중복 제거)를 계산
    const fileSet = new Set();
    let totalFileCount = 0;

    // DFS 함수 정의
    // 특정 폴더(folderName)를 시작으로 하위 모든 것을 탐색
    function dfs(folderName) {
      // 1. 현재 폴더에 있는 파일들을 확인
      if (fileMap.has(folderName)) {
        const files = fileMap.get(folderName);
        for (const file of files) {
          fileSet.add(file); // 파일 종류 (Set이라 자동 중복 제거)
          totalFileCount++;  // 파일 총 개수
        }
      }

      // 2. 하위 폴더가 있다면 재귀적으로 탐색
      if (folderGraph.has(folderName)) {
        const childFolders = folderGraph.get(folderName);
        for (const child of childFolders) {
          dfs(child);
        }
      }
    }

    // 탐색 시작
    dfs(currentFolder);

    // 결과 저장 (파일 종류 개수, 총 파일 개수)
    results.push(`${fileSet.size} ${totalFileCount}`);
  }

  // 한 번에 출력 (시간 초과 방지)
  console.log(results.join("\n"));
}

solution(input);