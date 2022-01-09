function solution(n) {
    let answer = '';
    while(n) {
        if(n % 3 == 0) { answer += 4; n = parseInt(n / 3) - 1; }
        else { answer += n % 3; n = parseInt(n / 3); }
    } return answer.split("").reverse().join("");
}
