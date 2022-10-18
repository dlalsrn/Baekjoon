import sys
N = int(sys.stdin.readline().strip())
S = int(sys.stdin.readline().strip())
IO = sys.stdin.readline().strip()
cnt = 0
total = 0
i = 1
while i < S-1:
    if IO[i-1] == 'I' and IO[i] == 'O' and IO[i+1] == 'I':
        cnt += 1
        if cnt == N:
            cnt -= 1
            total += 1
        i += 1
    else:
        cnt = 0
    i += 1
print(total)