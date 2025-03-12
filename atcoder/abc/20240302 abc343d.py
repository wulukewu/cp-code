import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import numpy
n, t = map(int, input().split())
A = []; B = []
for _ in range(t):
    ar = list(map(int, input().split()))
    A.append(ar[0])
    B.append(ar[1])

S = [0] * n
for i in range(t):
    S[A[i]-1] += B[i]
    print(len(list(numpy.unique(S))))