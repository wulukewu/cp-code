import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = []
B = []
C = []
for _ in range(n-1):
    a, b, c = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)

def dfs(x):
    global s, visit, ans
    # print(x, s, visit)

    det = True
    for i in range(n):
        if visit[i] == 0:
            det = False
            break
    
    if det: ans = min(ans, s)

    for i in range(n-1):
        if B[i] == x and visit[A[i]-1] == 0:
            visit[A[i]-1] = 1
            s += C[i]
            dfs(A[i])
            s += C[i]
            # visit[A[i]-1] = 0
        if A[i] == x and visit[B[i]-1] == 0:
            visit[B[i]-1] = 1
            s += C[i]
            dfs(B[i])
            s += C[i]
            # visit[B[i]-1] = 0

ans = 10**10
for i in range(1, n+1):
    visit = [0] * n
    visit[i-1] = 1
    s = 0
    dfs(i)
    # ans = min(ans, s)
print(ans)