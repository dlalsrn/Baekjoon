import sys
MOD = 1000000007

def pow(x, n):
    if n == 1:
        return x
    if n % 2 == 0:
        return (pow(x, n//2)**2) % MOD
    else:
        return (pow(x, (n-1)//2)**2 * x) % MOD

M = int(input())
fac = [1]
s = 1
for i in range(1, 4000001):
    s = (s*i) % MOD
    fac.append(s)

for i in range(M):
    N, K = map(int, sys.stdin.readline().strip().split())
    a = fac[N]
    b = fac[K]
    c = fac[N-K]
    temp = pow((b*c) % MOD, MOD-2)
    total = a*temp % MOD
    sys.stdout.write(str(total)+'\n')