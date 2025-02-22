import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))

a = k
t = 1
for i in range(n):
    if a >= A[i]:
        a -= A[i]
    else:
        t += 1
        a = k - A[i]

print(t)