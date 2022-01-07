function solution(distance, rocks, n) {
    let answer = 0;
    rocks.sort((a, b) => a - b);
    
    let l = 0, r = distance;
    while(l <= r) {
        let m = parseInt((l + r) / 2);
        let last = 0, cnt = 0;
        for(let i=0 ; i<rocks.length ; ++i) {
            if(rocks[i] - last < m) cnt++;
            else last = rocks[i];
        }
        if(distance - last < m) cnt++;
        if(cnt <= n) {
            answer = Math.max(answer, m);
            l = m + 1;
        } else r = m - 1;
    }
    return answer;
}
