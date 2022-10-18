MOD = 1000000007

def factorial(n):
    sum = 1
    for i in range(1, n+1, 1):
        sum = (sum*i) % MOD
    return sum

def pow(x, n):
    if n == 1:
        return x % MOD
    if n % 2 == 0:
        return (pow(x, n//2)**2) % MOD
    else:
        return (pow(x, (n-1)//2)**2 * x) % MOD

N, K = map(int, input().split())
a = factorial(N)
b = factorial(K)
c = factorial(N-K)

temp = pow(b*c, MOD-2) % MOD
total = a*temp % MOD
print(total)