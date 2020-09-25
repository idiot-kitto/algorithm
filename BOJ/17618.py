import sys
n = int(sys.stdin.readline())
ans = 0
for i in range(n,0,-1):
    tmp = 0
    s = str(i)
    for j in range(0,len(s)):
        tmp += int(s[j])
    if(i%tmp == 0):
        ans += 1
print(ans)

## PyPy3
