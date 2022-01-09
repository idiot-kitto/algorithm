function solution(s)
{
    let arr = [];
    for(let i=0 ; i<s.length ; ++i) {
        if(!arr.length || arr[arr.length - 1] !== s[i]) arr.push(s[i]);
        else arr.pop();
    }
    return arr.length ? 0 : 1;
}
