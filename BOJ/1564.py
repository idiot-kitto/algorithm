import sys

a=[0,0,0,0,0,0,0,0,0]
a.append("36288")
for i in range(10,1000001):
  s = str(int(a[-1])*i)
  s = s.rstrip("0")
  a.append(s[-12:])

n=int(sys.stdin.readline())
print(a[n][-5:])
