import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math
a, b = input().split()
a = int(a)
# b = int(b[0]) + int(b[-2:]) / 100
b = float(b)

ans = math.floor(a * b)
print(ans)