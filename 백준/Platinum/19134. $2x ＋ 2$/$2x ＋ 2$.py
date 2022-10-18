mx = int(input())
s = 0

while True:
    if mx == 1:
        s += 1
        break
    mn = mx//2
    s += (mx - mn + 1)
    if mn == 1:
        break

    if mn % 2 == 0:
        mn = mn//2
        if mn == 1:
            break
        else:
            mn -= 1
    else:
        mn = mn//2
        if mn == 1:
            break
    if mn == 1:
        break
    else:
        mx = mn - 1
print(int(s))