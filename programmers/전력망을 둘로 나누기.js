let pa = new Array(101);

function find(a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
function merge(a, b) { pa[find(b)] = find(a); }

function solution(n, wires) {
    let answer = 1e9;
    
    for(let i=0 ; i<wires.length ; ++i) {
        pa = new Array(101, 0);
        for(let k=0 ; k<101 ; ++k) pa[k] = k;
        
        let obj = {};
        
        for(let j=0 ; j<wires.length ; ++j) {
            if(j == i) continue;
            merge(wires[j][0], wires[j][1]);
        }
        
        for(let k=1 ; k<=n ; ++k) {
            if(!obj[find(k)]) obj[find(k)] = 1;
            else obj[find(k)]++;
        }
        answer = Math.min(answer, Math.abs(Object.entries(obj)[0][1] - Object.entries(obj)[1][1]));
    }
    
    return answer;
}
