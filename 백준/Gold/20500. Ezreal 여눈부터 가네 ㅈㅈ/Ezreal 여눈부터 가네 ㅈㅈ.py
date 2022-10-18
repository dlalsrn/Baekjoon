n = int(input())
total = 0
if n == 1:
    print(total)
elif n == 2:
    print(1)
else:
    sum = 1
    for i in range(3, n+1):
        if i % 2 == 0:
            total = sum + 1
        else:
            total = sum
        sum += total
    print(total % 1000000007)