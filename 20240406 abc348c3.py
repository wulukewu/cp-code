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

for i in range(N-1):
    for j in range(N-i-1):
        if C[j] > C[j+1]:
            C[j], C[j+1] = C[j+1], C[j]
            A[j], A[j+1] = A[j+1], A[j]

# print(A, C)

now = C[0]
M = []
for i in range(N):
    if i == 0:
        m = A[i]
        next
    if C[i] == now:
        m = min(m, A[i])
    else:
        M.append(m)
        now = C[i]
        m = A[i]
M.append(m)

ans = max(M)
print(ans)