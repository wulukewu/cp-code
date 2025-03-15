import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

s = abs(A[0]) + abs(A[-1])
for i in range(n-1):
    s += abs(A[i]-A[i+1])
# print(s)

for i in range(n):
    t = s
    if i == 0:
        t -= abs(A[i])
        t -= abs(A[i]-A[i+1])
        t += abs(A[i+1])
    elif i == n-1:
        t -= abs(A[i-1]-A[i])
        t -= abs(A[i])
        t += abs(A[i-1])
    else:
        t -= abs(A[i-1]-A[i])
        t -= abs(A[i]-A[i+1])
        t += abs(A[i-1]-A[i+1])
    print(t)