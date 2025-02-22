import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# C = A + B


A.sort()
# B.sort()
# C.sort()

det = False
for i in range(n-1):
    if A[i+1] - A[i] == 1:
        det = True
        break

if det:
    print('Yes')
else:
    print('No')