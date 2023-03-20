import sys

exp = list(sys.stdin.readline())
del exp[-1]

ans = []
opst = []
paraop = []
cnt = 0

i = 0
while i < len(exp):
    if exp[i].isalpha():
        ans.append(exp[i])
        i += 1
    elif exp[i] == '(':
        paraop.append(exp[i])
        cnt += 1
        i += 1
        while cnt > 0:
            if exp[i] == '(':
                paraop.append(exp[i])
                cnt += 1
            elif exp[i] == ')':
                cnt -= 1
                while paraop and paraop[-1] != '(':
                    ans.append(paraop.pop())
                paraop.pop()
            elif exp[i].isalpha():
                ans.append(exp[i])
            else:
                if exp[i] == '*' or exp[i] == '/':
                    while paraop and (paraop[-1] == '*' or paraop[-1] == '/'):
                        ans.append(paraop.pop())
                    paraop.append(exp[i])
                elif exp[i] == '+' or exp[i] == '-':
                    while paraop and paraop[-1] != '(':
                        ans.append(paraop.pop())
                    paraop.append(exp[i])
            i += 1
        k = 0
        while k < len(paraop):
            if paraop[k] == '(':
                paraop.pop()
            else:
                ans.append(paraop.pop())
    elif exp[i] == '*' or exp[i] == '/':
        while opst and (opst[-1] == '*' or opst[-1] == '/'):
            ans.append(opst.pop())
        opst.append(exp[i])
        i += 1
    elif exp[i] == '+' or exp[i] == '-':
        while opst:
            ans.append(opst.pop())
        opst.append(exp[i])
        i += 1

while opst:
    ans.append(opst.pop())
print("".join(ans))