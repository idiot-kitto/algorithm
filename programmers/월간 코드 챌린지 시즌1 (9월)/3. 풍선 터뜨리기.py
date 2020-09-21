arr1=[0 for i in range(1000001)]
arr2=[0 for i in range(1000001)]
def solution(a):
    answer = len(a)
    arr1[0] = a[0]
    arr2[len(a)-1] = a[len(a)-1]
    for i in range(1,len(a)):
        if arr1[i-1] > a[i]: arr1[i] = a[i]
        else: arr1[i] = arr1[i-1]
    for i in range(len(a)-2,0,-1):
        if arr2[i+1] > a[i]: arr2[i] = a[i]
        else: arr2[i] = arr2[i+1]
    if(len(a)<3): return answer
    else:
        for i in range(1,len(a)-1):
            if a[i] > arr1[i] and a[i] > arr2[i]: answer -= 1
    return answer
