def search(n, min, max, ary):
    if min > max:
        print(0)
        return
    mid = int((min+max)/2)
    if ary[mid] == n:
        print(1)
        return
    elif ary[mid] < n:
        search(n, mid+1, max, ary)
    elif ary[mid] > n:
        search(n, min, mid-1, ary)

N = int(input())
ary_N = list(map(int, input().split()))
ary_N.sort()
M = int(input())
ary_M = list(map(int, input().split()))
for i in ary_M:
    search(i, 0, len(ary_N)-1, ary_N)