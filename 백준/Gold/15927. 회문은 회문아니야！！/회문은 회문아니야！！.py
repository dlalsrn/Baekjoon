import sys
x = sys.stdin.readline().strip()
TF = False
if x.count(x[0]) == len(x):
    print(-1)
else:
    while len(x):
        for i in range(len(x)//2):
            if x[i] != x[-1-i]:
                print(len(x))
                TF = True
                break
        if TF:
            break
        x = x[1:]