import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math

N = int(input())
p = list(map(int, input().split()))

arr = []
j = 0
for i in range(N):
    if p[i] == i + 1:
        j += 1
    elif j != 0:
        arr.append(j)
        j = 0
if j != 0:
    arr.append(j)
# print(arr)

ans = 0
for i in arr:
    ans += math.ceil(i/2)

print(ans)