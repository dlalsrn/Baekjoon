# AC
import sys
from collections import deque
N = int(input())
for k in range(N):
    RV = False
    TF = False
    deq = deque()
    i = 0
    commend = sys.stdin.readline().strip()
    length = int(input())
    ary = sys.stdin.readline().strip().lstrip('[').rstrip(']').split(',')
    for i in ary:
        deq.append(i)
    if TF:
        continue
    for i in range(len(commend)):
        if commend[i] == 'R':
            if RV == False:
                RV = True
            else:
                RV = False
        else:
            if RV == False:
                if len(deq) == 0 or deq[0] == '':
                    print("error")
                    TF = True
                    break
                else:
                    deq.popleft()
            else:
                if len(deq) == 0 or deq[0] == '':
                    print("error")
                    TF = True
                    break
                else:
                    deq.pop()
    if TF:
        continue
    if RV == False:
        print('[', end='')
        print(','.join(str(x) for x in deq), end='')
        print(']')
    else:
        deq.reverse()
        print('[', end='')
        print(','.join(str(x) for x in deq), end='')
        print(']')