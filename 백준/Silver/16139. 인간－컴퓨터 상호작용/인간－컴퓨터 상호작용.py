import sys
x = sys.stdin.readline().strip()
N = int(sys.stdin.readline().strip())
finish = []
for i in "abcdefghijklmnopqrstuvwxyz":
    total = []
    cnt = 0
    for j in x:
        if j == i:
            cnt += 1
        total.append(cnt)
    finish.append(total)

for i in range(N):
    alpha, l, r = sys.stdin.readline().split()
    temp = finish[ord(alpha)-97]
    cnt = temp[int(r)] - temp[int(l)]
    if x[int(l)] == alpha:
        cnt += 1
    sys.stdout.write(str(cnt)+'\n')