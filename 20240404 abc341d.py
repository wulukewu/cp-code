import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

import math
n, m, k = map(int, input().split())
l = math.lcm(n, m)

def div(x):
    return math.ceil(x/n) + math.ceil(x/m) - 2 * math.ceil(x/l)

d = 10 ** len(str(k))
x = l * k
y = div(x)

while y != k-1:
    y = div(x)
    if y < k-1:
        pass
    else:
        pass