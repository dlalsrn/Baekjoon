N = int(input())
rank = []
ans = []
Tier = {'B':0, 'S':1, 'G':2, 'P':3, 'D':4}

T = input().split()
for x in T:
    rank.append(x)

for i in range(N - 1):
    if Tier[rank[i][0]] > Tier[rank[i + 1][0]]:
        ans.append(rank[i])
        break
    elif Tier[rank[i][0]] == Tier[rank[i + 1][0]] and int(rank[i][1:]) < int(rank[i + 1][1:]):
        ans.append((rank[i]))
        break;

for i in range(N - 1, 0, -1):
    if Tier[rank[i][0]] < Tier[rank[i - 1][0]]:
        ans.append(rank[i])
        break
    elif Tier[rank[i][0]] == Tier[rank[i - 1][0]] and int(rank[i][1:]) > int(rank[i - 1][1:]):
        ans.append((rank[i]))
        break;

if len(ans) == 0:
    print("OK")
else:
    print("KO")
    if Tier[ans[0][0]] > Tier[ans[1][0]]:
        print(ans[1], ans[0])
    elif int(ans[0][1:]) < int(ans[1][1:]):
        print(ans[1], ans[0])
    else:
        print(ans[0], ans[1])