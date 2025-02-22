import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def dfs(x, v, arr):
    ans = 0
    v[x] = 1
    for j in arr[x]:
        if v[j] == 1:
            continue
        ans += dfs(j, v, arr)
    return ans + 1

n = int(input())
arr = [[] for _ in range(n + 1)]
v = [0] * (n + 1)
v[1] = 1

for i in range(n - 1):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

sum_values = []
for i in range(len(arr[1])):
    sum_values.append(dfs(arr[1][i], v, arr))

sum_values.sort(reverse=True)
print(n - sum_values[0])
