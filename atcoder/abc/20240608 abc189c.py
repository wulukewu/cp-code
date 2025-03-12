import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))
k = 0

for l in range(n):
    mn = A[l]
    for r in range(l+1, n+1):
        # m = A[l:r]
        mn = min(mn, A[r-1])
        k = max(k, mn * (r-l))

print(k)