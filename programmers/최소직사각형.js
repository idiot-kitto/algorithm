function solution(sizes) {
    var answer = 0;
    for(let i=0 ; i<sizes.length ; ++i)
        if(sizes[i][0] > sizes[i][1]) 
            [sizes[i][0], sizes[i][1]] = [sizes[i][1], sizes[i][0]];
    
    let a = 0, b = 0;
    for(let i=0 ; i<sizes.length ; ++i) {
        a = Math.max(a, sizes[i][0]); 
        b = Math.max(b, sizes[i][1]);
    } answer = a * b;
    
    return answer;
}
