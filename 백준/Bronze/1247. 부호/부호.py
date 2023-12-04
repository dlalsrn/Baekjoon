for x in range(0, 3):
    N = int(input())
    s = 0
    for i in range(N):
        s += int(input())

    if (s < 0):
        print("-")
    elif (s > 0):
        print("+")
    else:
        print(0)