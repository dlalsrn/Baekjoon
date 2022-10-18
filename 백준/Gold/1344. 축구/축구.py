import math

sosu = [2,3,5,7,11,13,17]
A = int(input())
B = int(input())
total = 0.0
diff = 0.0
for i in sosu:
    total += math.comb(18, i)*pow((A/100), i)*pow(1-(A/100), 18-i)
    total += math.comb(18, i)*pow((B/100), i)*pow(1-(B/100), 18-i)

for i in sosu:
    for j in sosu:
        diff += math.comb(18, i)*pow((A/100), i)*pow(1-(A/100), 18-i) * math.comb(18, j)*pow((B/100), j)*pow(1-(B/100), 18-j)

print(total-diff)
