import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
arr = [[] for _ in range(N+1)]
for _ in range(N-1):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

# print(arr)

went = [0 for _ in range(N+1)]
went[1] = 1

def dfs(x):
    # print(x)
    y = 0
    went[x] = 1
    for i in range(len(arr[x])):
        if went[arr[x][i]]:
            continue
        # print(i)
        # went[i] = 1
        y += dfs(arr[x][i])
    return y + 1

M = [0]
# print(max(M))
for i in arr[1]:
    # went[i] = 1
    M.append(dfs(i))

# print(M)
ans = N - max(M)
# ans = max(M)
print(ans)