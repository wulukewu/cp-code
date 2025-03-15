import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))

A.sort()
# print(A)

kk = n - k - 1
# print(kk)

ans = A[-1] - A[0]
for i in range(k+1):
    # print(i, ans, A[i+kk]-A[i])
    ans = min(ans, A[i+kk]-A[i])

print(ans)