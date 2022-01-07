function solution(word) {
    let arr = ["A", "E", "I", "O", "U"], cnt = 1, ans = {};
    for(let a=0 ; a<5 ; ++a) {
        let s = arr[a];
        ans[s] = cnt++;
        for(let b=0 ; b<5 ; ++b) {
            s += arr[b];
            ans[s] = cnt++;
            for(let c=0 ; c<5 ; ++c) {
                s += arr[c];
                ans[s] = cnt++;
                for(let d=0 ; d<5 ; ++d) {
                    s += arr[d];
                    ans[s] = cnt++;
                    for(let e=0 ; e<5 ; ++e) {
                        s += arr[e];
                        ans[s] = cnt++;
                        s = s.slice(0, -1);                        
                    } s = s.slice(0, -1);
                } s = s.slice(0, -1);
            } s = s.slice(0, -1);
        } s = s.slice(0, -1);
    }
    
    return ans[word];
}
