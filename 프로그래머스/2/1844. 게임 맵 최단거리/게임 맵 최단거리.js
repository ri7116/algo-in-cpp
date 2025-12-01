// 최단거리 bfs
let dy = [1, 0, -1,  0]
let dx = [0, 1,  0, -1]

function solution(maps) {
    var answer = 0;

    let visited = [];
    
    for(let i = 0; i < maps.length; i++){
        visited[i] = [];
        for(let j = 0; j < maps[0].length; j++){
            visited[i][j] = 0;
        }
    }
    
    console.log(visited);
    
    let q = [];
    
    q.push([0, 0, 1])
    visited[0][0] = 1;
    
    while(q.length != 0){
        let y = q[0][0];
        let x = q[0][1];
        let dis = q[0][2];
        q.shift(); //시간 복잡도가 N이긴 해서 맞긴 않고 사파
        
        for(let i = 0; i < 4; i++){
            let ny = y + dy[i];
            let nx = x + dx[i];
            
            if(ny < 0 || ny >= maps.length || nx < 0 || nx >= maps[0].length) continue;
            if(maps[ny][nx] == 0) continue;
            if(visited[ny][nx] != 0) continue;
            
            visited[ny][nx] = dis + 1;
            q.push([ny, nx, dis + 1]);
        }
    
    
    }
    answer = visited[maps.length - 1][maps[0].length - 1]
    if(answer == 0) answer = -1;
    return answer;
}