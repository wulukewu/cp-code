import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math

N = int(input())
a = list(map(int, input().split()))
p2 = 0; p4 = 0
for i in a:
    if i % 4 == 0:
        p4 += 1
    elif i % 2 == 0:
        p2 += 1

# print(p2, p4)
if p2 != 0:
    p4 -= 1
    N -= 1

b = math.floor((N-p2)/2)
# print(b)
if p4 >= b:
    print('Yes')
else:
    print('No')