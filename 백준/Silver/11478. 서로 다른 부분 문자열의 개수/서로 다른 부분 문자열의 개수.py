s = set()
x = input()

for i in range(1, len(x)+1):
    for j in range(len(x)-i+1):
        s.add(x[j:i+j])
print(len(s))