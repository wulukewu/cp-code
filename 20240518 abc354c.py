import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
A = []; C = []
for _ in range(n):
    a, c = map(int, input().split())
    A.append(a)
    C.append(c)

