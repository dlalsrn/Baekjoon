# 못푼 문제

def tf(x):
    op = ['+', '-', '*', '/']
    num = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
    cnt = 0
    check = 0
    op_check = 0
    if (x[-1] in op) or x[-1] == '(':
        print("ROCK")
        return 0
    if (x[0] in op) or x[0] == ')':
        print("ROCK")
        return 0
    for i in range(len(x)-1):
        if x[i] == '(':
            check = 1
            cnt += 1
        if x[i] == ')':
            check = 0
            cnt -= 1
            if cnt < 0:
                print("ROCK")
                return 0
        if (x[i] in op) or x[i] == '(':
            if x[i] in op:
                if check == 1:
                    op_check = 1
            if (x[i + 1] in op) or x[i+1] == ')':
                print("ROCK")
                return 0
        elif x[i] in num:
            if x[i+1] == ')':
                if check != 0:
                    if op_check == 0:
                        print("ROCK")
                        return 0
                    else:
                        op_check = 0
            if (x[i+1] == '('):
                print("ROCK")
                return 0
        elif x[i] == ')':
            if (x[i+1] in num) or x[i+1] == '(':
                print("ROCK")
                return 0
    if x[len(x)-1] == ')':
        cnt -= 1
    if cnt != 0:
        print("ROCK")
        return 0

def operate(n1, n2, op):
    if op == '+':
        return n1+n2
    elif op == '-':
        return n1-n2
    elif op == '*':
        return n1*n2
    elif op == '/':
        return n1//n2

def main():
    x = input()
    if tf(x) == 0:
        return
    sum = ""
    num = []
    oper = []

    for i in range(len(x)):
        if x[i] == '*' or x[i] == '/' or x[i] == '-' or x[i] == '+' or x[i] == '(' or x[i] == ')':
            if len(sum) != 0:
                total = int(sum)
                num.append(total)
                sum = ""
            temp = x[i]
            if temp == '*' or temp == '/' or temp == '(':
                if temp == '*' or temp == '/':
                    while len(oper) != 0 and oper[-1] == '/':
                        op = oper.pop()
                        n = num.pop()
                        m = num.pop()
                        s = operate(m, n, op)
                        num.append(s)
                oper.append(temp)
            elif temp == '-' or temp == '+':
                while len(oper) != 0 and (oper[-1] == '*' or oper[-1] == '/' or oper[-1] == '-'):
                    op = oper.pop()
                    n = num.pop()
                    m = num.pop()
                    s = operate(m, n, op)
                    num.append(s)
                oper.append(temp)
            else:
                while oper[-1] != '(':
                    op = oper.pop()
                    n = num.pop()
                    m = num.pop()
                    s = operate(m, n, op)
                    num.append(s)
                oper.pop()
        else:
            sum += x[i]
    if (len(sum) != 0):
        s = int(sum)
        num.append(s)

    while(len(oper) != 0):
        op = oper.pop()
        n = num.pop()
        m = num.pop()
        s = operate(m, n, op)
        num.append(s)
    print(num[-1])

main()