function solution(n, edge) {
    let answer = [];
    let visited = [];
    
    for(let i = 0; i <=n; i++){
        visited[i] = 0;
    }
    
    //console.log(visited);
    
    let v = []
    
    for(let i = 0 ; i < edge.length; i++){
        if(v[edge[i][0]] == undefined) v[edge[i][0]] = []
        if(v[edge[i][1]] == undefined) v[edge[i][1]] = []
        
        v[edge[i][0]].push(edge[i][1]);
        v[edge[i][1]].push(edge[i][0]);
    }
    
    //console.log( v );
    
    let q = [] 
    
    q.push([1,1]);
    visited[1] = 1;
    //console.log("1 방문");
    
    while(q.length != 0 ){
        let cur_node = q[0][0];
        let cur_dis = q[0][1];
        q.shift(); //이거 일단 야매임
        
        for(let next of v[cur_node]){
            //console.log(next, "일단 들어감")
            if(visited[next] != 0) continue; //이미 방문 했으면 넘어가
            
            visited[next] = cur_dis + 1;
            //console.log("i 방문");
            
            q.push([next, cur_dis + 1]);
        }
    }
    
    let max_dis = 0;
    
    for(let i = 1; i <= n; i++){
        max_dis = Math.max(visited[i], max_dis);    
    }
    
    for(let i = 1; i <= n; i++){
        if(visited[i] == max_dis) answer.push(i);    
    }
    
    // console.log("====================================")
    // for(let next of v[1]){
    //         console.log(next);
    // }
    
    //console.log(max_dis)
    
    //console.log(answer);
    
    return answer.length;
}