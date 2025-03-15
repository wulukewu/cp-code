import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, h, w = map(int, input().split())
A = []; B = []
for _ in range(n):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

