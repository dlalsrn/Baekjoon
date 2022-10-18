from decimal import *
getcontext().prec = 1000000
def pow(x, n):
    if n == 1:
        return x
    if n % 2 == 0:
        return pow(x, n//2)**2
    else:
        return pow(x, (n-1)//2)**2 * x

a, b = input().split()
c = Decimal(pow(Decimal(a),Decimal(b)))
print("{:f}".format(c))