import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())

A = []
for _ in range(n):
    A.append(input())

B = []
for _ in range(m):
    B.append(input())

det = False
for i in range(n-m+1):
    for j in range(n-m+1):
        det2 = True
        for ii in range(m):
            for jj in range(m):
                if A[i+ii][j+jj] != B[ii][jj]: det2 = False; break
            if not det2: break
        if det2: det = True; break
    if det: break

if det:
    print('Yes')
else:
    print('No')
