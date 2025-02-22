import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k, x = map(int, input().split())
A = list(map(int, input().split()))

for i in range(n+1):
    if i == k:
        print(x, end=' ')
        if i != n:
            print(A[i], end=' ')
    elif i == n:
        break
    else:
        print(A[i], end=' ')
