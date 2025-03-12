import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

sx, sy = map(int, input().split())
tx, ty = map(int, input().split())

a1 = abs(sy-ty)
if (sx+tx) % 2 == 0: a2 = sx+1
else: a2 = sx-1
a3 = min(abs(tx-sx), abs(tx-a2))

if a1 < a3:
    a4 = a3 - a1
    a5 = a4//2
    if a4%2 == 1: a5 += 1
    a1 += a5

print(a1)