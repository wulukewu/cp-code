import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

xa, ya, xb, yb, xc, yc = map(int, input().split())

a = xb - xa
b = yb - ya
c = xc - xa
d = yc - ya
s = abs(a*d - b*c) / 2

print(s)