import sys
n = int(sys.stdin.readline())
for i in range(0,n):
    ans = 0
    s = sys.stdin.readline().strip()
    l = 0
    r = len(s)-1
    while l<=r:
        if s[l] == s[r]:
            l+=1
            r-=1
        else:
            ans=2
            break
    if ans == 0:
        print(ans)
    else:
        check = False
        ll = 0
        rr = len(s)-1
        ans = 1
        while ll<=rr:
            if s[ll] == s[rr]:
                ll+=1
                rr-=1
            else:
                if check == False:
                    ll+=1
                    check = True
                    continue
                else:
                    ans = 2
                    break
        if(ans == 1):
            print(ans)
        else:
            check = False
            ll = 0
            rr = len(s) - 1
            ans = 1
            while ll <= rr:
                if s[ll] == s[rr]:
                    ll += 1
                    rr -= 1
                else:
                    if check == False:
                        rr -= 1
                        check = True
                        continue
                    else:
                        ans = 2
                        break
            print(ans)
