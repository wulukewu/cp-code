import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
AC = []
for _ in range(N):
    a, c = map(int, input().split())
    AC.append((a, c))

arr = sorted(AC, key=lambda x: x[1])

# print(arr)

now = arr[0][1]
M = []
for i in range(N):
    if i == 0:
        m = arr[i][0]
        next
    if arr[i][1] == now:
        m = min(m, arr[i][0])
    else:
        M.append(m)
        now = arr[i][1]
        m = arr[i][0]
M.append(m)

ans = max(M)
print(ans)