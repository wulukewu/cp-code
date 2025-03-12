import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

A, B, C, D = map(int, input().split())

a1 = (-1 * A) % 4
a2 = (-1 * A) // 4
b1 = (-1 * B) % 4
b2 = (-1 * B) // 4
c1 = (-1 * C) % 4
c2 = (-1 * C) // 4
d1 = (-1 * D) % 4
d2 = (-1 * D) // 4

# m = 