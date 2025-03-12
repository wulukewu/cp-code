import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = list(map(int, input().split()))

def f(x, y):
    return int(str(x)+str(y))

s = 0
for i in range(n-1):
    for j in range(i+1, n):
        t = f(A[i],A[j])
        # print(i, j, t)
        s += t
s %= 998244353
print(s)