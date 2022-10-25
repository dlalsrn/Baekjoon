from decimal import *
getcontext().prec = 150
getcontext().rounding = ROUND_HALF_UP
pi = Decimal('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762')

def sin_(x):
	x = x % (2 * pi)
	i, lasts, s, fact, num, sign = Decimal('1'), Decimal('0'), Decimal(str(x)), Decimal('1'), Decimal(str(x)), Decimal('1')
	while s != lasts:
		lasts = s
		i += 2
		fact *= i * (i - 1)
		num *= x * x
		sign *= -1
		s += num / fact * sign
	return Decimal(str(s))

A, B, C = input().split()
A = Decimal(A)
B = Decimal(B)
C = Decimal(C)
a = Decimal('0.0')
b = Decimal('1000000.0')
mid = Decimal(str(a + b)) / Decimal('2')
fx = Decimal(str(A * mid)) + Decimal(str(B * sin_(mid))) - C

while abs(fx) > 0.0000000000000001:
	if fx > 0:
		b = mid
	elif fx < 0:
		a = mid
	else:
		break
	mid = Decimal(str(a + b)) / Decimal('2')
	fx = Decimal(str(A * mid)) + Decimal(str(B * sin_(mid))) - C

print(mid)