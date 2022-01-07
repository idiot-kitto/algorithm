### 기본
- 사이즈 있는 배열 선언
  - ```let arr = new Array(101)```
- 객체 선언 ( C++의 map 비슷하게 사용 가능해 보임 )
  - ```let obj = {}```
- 객체를 배열로
  - key, value 값 둘다 : ```Object.entries(obj)```
  - key 값만 : ```Object.keys(obj)```
  - value 값만 : ```Object.values(obj)```

### 정렬
- 오름차순
  - ```arr.sort((a,b) => a - b)```
- 내림차순 
  - ```arr.sort((a,b) => b - a)```

### 수 다루기
- 1,000,000,000 -> 1e9 로 사용 가능
- max 함수
  - ```Math.max(a,b)```
- min 함수
  - ```Math.min(a,b)```
- 올림 
  - ```Math.ceil(n)```
- 내림 
  - ```Math.floor(n)```  OR  ```parseInt(n)```
- 반올림 
  - ```Math.round(n)```

- 문자열을 숫자로
  - ```parseInt(str)```
- 숫자를 문자열로
  - ```String(n)```

### Swap 
- ```[a, b] = [b, a]```

### 문자열
- 마지막 문자 자르기
  - ```s = s.slice(0, -1)```


### DSU
```
function find(a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
function merge(a, b) { pa[find(b)] = find(a); }
```
