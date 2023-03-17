N = int(input())
x = list(map(int, input().split()))
ans = 0
for i in x:
    if i == 0:
        ans += 2
    else:
        ans += 1/i

print(ans)