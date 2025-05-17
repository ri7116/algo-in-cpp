function solution(numbers, hand) {
    var answer = '';
    let map={
        '1':[0,0],
        '2':[0,1],
        '3':[0,2],
        '4':[1,0],
        '5':[1,1],
        '6':[1,2],
        '7':[2,0],
        '8':[2,1],
        '9':[2,2],
        '*':[3,0],
        '0':[3,1],
        '#':[3,2],
    }
    let left="*"
    let right="#"
    for(let e of numbers){
        if(e=='1' ||e=='4' ||e=='7' ){
            answer+='L';
            left=e;
        }
        
        if(e=='2' ||e=='5' ||e=='8' ||e=='0'){
            let a=map[e][0]-map[left][0]
            if(a<=0) a=a*-1
            let b=map[e][1]-map[left][1]
            if(b<=0) b=b*-1
            let c=map[e][0]-map[right][0]
            if(c<=0) c=c*-1
            let d=map[e][1]-map[right][1]
            if(d<=0) d=d*-1

            let vector_left=a+b;
            let vector_right=c+d;
            if(vector_left<vector_right){
                answer+='L';
                left=e;
            }
            else if(vector_left>vector_right){
                answer+='R';
                right=e;
            }
            else{
                if(hand=='right'){
                    answer+='R';
                    right=e;
                }
                else{
                    answer+='L';
                    left=e;
                }
            }
        }
        if(e=='3' ||e=='6' ||e=='9' ){
            answer+='R';
            right=e;
        }
        console.log(left)
        console.log(right)
    }
    return answer;
}