import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math

N = int(input())
xy = []
for _ in range(N):
    xy.append(list(map(int, input().split())))

for i in range(N):
    m = 0
    mi = 0

    for j in range(N):
        if i == j: next
        x1 = xy[i][0]
        y1 = xy[i][1]
        x2 = xy[j][0]
        y2 = xy[j][1]

        n = math.sqrt((x1-x2)**2 + (y1-y2)**2)
        # print(n,m,mi)
        if n > m:
            m = n
            mi = j
        
    print(mi + 1)
