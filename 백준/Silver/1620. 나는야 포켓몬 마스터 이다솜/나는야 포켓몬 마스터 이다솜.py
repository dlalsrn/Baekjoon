import sys
N, M = map(int, input().split())
dic = {}
dic_reverse = {}
for i in range(1, N+1):
    x = input()
    dic[i] = x
    dic_reverse[x] = i

for i in range(0, M):
    x = sys.stdin.readline().rstrip()
    if ord(x[0]) <= 57:
        print(dic[int(x)])
    else:
        print(dic_reverse[x])