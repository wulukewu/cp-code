import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))
arr = []
for i in range(n):
    if A[i] % k == 0:
        arr.append(str(A[i]//k))

s = ' '.join(arr)
print(s)