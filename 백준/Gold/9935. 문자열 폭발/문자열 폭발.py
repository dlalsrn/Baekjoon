a = input().strip()
boom = input().strip()
ary = []
for i in range(len(a)):
    ary.append(a[i])
    if len(a) >= len(boom):
        tmp = "".join(ary[-len(boom):])
        if tmp == boom:
            cnt = 0
            while cnt < len(boom):
                ary.pop()
                cnt += 1
if (len(ary) == 0):
    print("FRULA")
else:
    print("".join(ary))