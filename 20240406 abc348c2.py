import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = []
C = []
for _ in range(N):
    a, c = map(int, input().split())
    A.append(a)
    C.append(c)

arr = [-1] * (max(C) + 1)

for i in range(N):
    if arr[C[i]] == -1:
        arr[C[i]] = A[i]
    else:
        arr[C[i]] = min(arr[C[i]], A[i])

ans = max(arr)
print(ans)