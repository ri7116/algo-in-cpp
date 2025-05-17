

function solution(N, stages) {
    //실패율= 도달했으나 아직 클리어하지 못한 플레이어의 수 / 도달한 플레이어의 수 
    let visited= Array(N+1).fill(0);// 방문한 수 체크
    let current= Array(N+1).fill(0);// 현재 위치 
    // 실패율=current/visited
    // 실패율이 높은거부터 내림차순
    for(let i=0;i<stages.length;i++){
        for(let j=1;j<=stages[i];j++){
            visited[j]++;
        }
        current[stages[i]]++;
    }
    
    function cmp(a, b){
        let lossA=(visited[a]==0)?0:(current[a]/visited[a]);// 삼항연산자
        let lossB=(visited[b]==0)?0:(current[b]/visited[b]);
        
        //1은 모양을 그대로 유지 한다는 가정
        if(lossA<lossB){
            return 1
        }
        else if(lossA>lossB){
            return -1
        }
        else{
            if(a<b) return -1
            else return 1
        }
    }
    
    var answer = [];
    
    for(let i=1;i<=N;i++){
        let lossI=(visited[i]==0)?0:(current[i]/visited[i]);
        console.log(lossI)
    }
    
    for(let i=1;i<=N;i++){
        answer.push(i);
    }
    answer.sort(cmp);
    return answer;
}
//1. Array(N)은 0~N-1;
//2. -1일땐 순서유지(a가 왼쪽) 1일땐(a가 오른쪽) 뒤집어짐 https://ryusi-in.tistory.com/561