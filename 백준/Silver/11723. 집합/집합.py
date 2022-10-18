import sys
A = set()
N = int(input())
for i in range(N):
    x = sys.stdin.readline().split()
    if len(x) == 2:
        y = int(x[1])
        if x[0] == "add":
            A.add(y)
        elif x[0] == "check":
            if y in A:
                print(1)
            else:
                print(0)
        elif x[0] == "remove":
            A.discard(y)
        elif x[0] == "toggle":
            if y in A:
                A.discard(y)
            else:
                A.add(y)
    else:
        if x[0] == "all":
            A = set([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
        else:
            A.clear()