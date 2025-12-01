function solution(N, road, K) {
    var answer = 0;

    //n + 1, n + 1 2차원 배열 만들어야 함 인덱스 0번땜에 하나 빠짐을 주의
    
    let dp = []
    
    for (let i=0; i<=N; i++) {
        dp[i] = []
        
        for (let j=0; j<=N; j++) {
            dp[i][j] = 210000000
            if (i == j) dp[i][j] = 0
        } 
    }

    //console.log(dp)
    
    for (let i = 0; i < road.length ; i++) {
        dp[road[i][0]][road[i][1]] = Math.min(dp[road[i][0]][road[i][1]], road[i][2])
        dp[road[i][1]][road[i][0]] = Math.min(dp[road[i][1]][road[i][0]], road[i][2])
    }

    //console.log(dp)

    for (let k = 1; k <= N ; k++) {
        for( let i = 1; i <= N ; i++) {
            for( let j = 1 ; j <= N ;j++) {
                if(dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = dp[i][k] + dp[k][j] 
            }
        }
    }
    
    console.log(dp)
    
    for(let i = 1; i <= N; i++) {
        if(dp[1][i] <= K) {
            answer++
            console.log(i, "는 만족 했습니다")
        }
    }
    console.log(dp[1][5])
    
    return answer;
}
// 자바스크립트 num은 몇까지 가능한 거지? 좀 신기하네..
// 간선은 양방향이고 양방향 간선의 최소값을 넣어야 함을 잊지말아라



