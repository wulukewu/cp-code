import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = []; B = []
C = []
for _ in range(n):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(b-a)

ans = sum(A) + max(C)
print(ans)