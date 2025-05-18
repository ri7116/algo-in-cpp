function solution(survey, choices) {
    var answer = '';
    let point={
        "R":0,
        "T":0,
        "C":0,
        "F":0,
        "J":0,
        "M":0,
        "A":0,
        "N":0,
    }
    for(let i=0;i<survey.length;i++){
        if(survey[i]=="RT"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="TR"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="FC"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="CF"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="MJ"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="JM"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="AN"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
        if(survey[i]=="NA"){
            if(choices[i]==1) point[survey[i][0]]+=3;
            if(choices[i]==2) point[survey[i][0]]+=2;
            if(choices[i]==3) point[survey[i][0]]+=1;
            if(choices[i]==5) point[survey[i][1]]+=1;
            if(choices[i]==6) point[survey[i][1]]+=2;
            if(choices[i]==7) point[survey[i][1]]+=3;
        }
    }
    if(point["R"]>point["T"]) answer+="R"; 
    else if(point["T"]>point["R"]) answer+="T";
    else answer+="R";
    
    if(point["C"]>point["F"]) answer+="C"; 
    else if(point["F"]>point["C"]) answer+="F";
    else answer+="C";
    
    if(point["J"]>point["M"]) answer+="J"; 
    else if(point["M"]>point["J"]) answer+="M";
    else answer+="J";
    
    if(point["A"]>point["N"]) answer+="A"; 
    else if(point["N"]>point["A"]) answer+="N";
    else answer+="A";
    return answer;
}
//객체를 쓸 경우에 A(X) "A"(O)
//저는 따녹형 할게연
//뇌세포 살려~~~~~~~~~~~