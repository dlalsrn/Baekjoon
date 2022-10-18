import sys
N, M = input().split()
DNS = {}
for i in range(int(N)):
    address, password = sys.stdin.readline().split()
    DNS[address] = password
for i in range(int(M)):
    address = input()
    print(DNS[address])
