U, V = map(int, input().split())
A = input()
B = input()
ras, auq = 0, 0
t1, t2 = 1, 1
N = len(A)

if U == V :
    win = 0
    for i in range(N):
        if A[i] == B[i]: continue
        elif A[i] > B[i]:
            win = 1
            break;
        else:
            win = 2
            break;

    if win == 1: print("ras")
    elif win == 2:print("auq")
    else: print("rasauq")   
elif N <= 24:
    for i in range(N - 1, -1, -1):
        ras += t1 * (ord(A[i]) - 48)
        auq += t2 * (ord(B[i]) - 48)
        t1 *= U
        t2 *= V

    if ras > auq: print("ras")
    elif ras < auq: print("auq")
    else: print("rasauq")
else:
    if U > V:
        print("ras")
    else:
        print("auq")
