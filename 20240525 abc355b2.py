import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

C = A + B

A.sort()
# B.sort()
C.sort()

det = False
for i in range(n+m-1):
    try:
        a = A.index(C[i])
        b = A.index(C[i+1])
        if b - a == 1:
            det = True
            break
    except:
        next

if det:
    print('Yes')
else:
    print('No')