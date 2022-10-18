x = input()
temp = ""
total = ""
i = 0
for j in range(len(x)):
    if x[j] == '+' or x[j] == '-':
        total += str(int(temp))
        total += x[j]
        temp = ""
    else:
        temp += x[j]
total += str(int(temp))
x = total
total = ""
while i < len(x):
    if x[i] == '-':
        total += '-'
        for j in range(i+1, len(x)):
            if x[j] == '-':
                total += str(eval(x[i + 1:j]))
                i = j
                break
            elif j == len(x) - 1:
                total += str(eval(x[i+1:]))
                i = j + 1
                break
    else:
        total += x[i]
        i += 1

print(eval(total))