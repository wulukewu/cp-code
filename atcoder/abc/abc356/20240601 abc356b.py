import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
A = list(map(int, input().split()))
X = []
for _ in range(n):
    X.append(list(map(int, input().split())))

det = True
for i in range(m):
    a = A[i]
    b = 0
    for j in range(n):
        b += X[j][i]
    if a > b:
        det = False
        break

if det:
    print('Yes')
else:
    print('No')