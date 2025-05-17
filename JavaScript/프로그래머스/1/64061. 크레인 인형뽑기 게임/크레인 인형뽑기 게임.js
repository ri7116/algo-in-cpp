function solution(board, moves) {
    var answer = 0;
    let stk=[];
    //console.log(board[0].length);
    //console.log(board.length);
    for(let i=0;i<moves.length;i++){
        for(let j=0;j<board.length;j++){
            if(board[j][moves[i]-1]!=0) {
                console.log(board[j][moves[i]-1]);
                if(stk[stk.length-1]==board[j][moves[i]-1]){
                    board[j][moves[i]-1]=0;
                    stk.pop();
                    answer++;
                    answer++;
                    break;
                }
                else {
                    stk.push(board[j][moves[i]-1]);
                    board[j][moves[i]-1]=0;
                    break;
                }
            }
        }
    }
    console.log(stk);
    return answer;
}