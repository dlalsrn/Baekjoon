x = int(input())
total = 1
cnt = 0
for i in range(x, 0, -1):
    total *= i
total = str(total)
while total[-1] == '0':
    cnt += 1
    total = total[:-1]
print(cnt)