import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math
a, b, n = map(int, input().split())

x = min(b-1, n)
c = math.floor(a*x/b) - a * math.floor(x/b)
print(c)