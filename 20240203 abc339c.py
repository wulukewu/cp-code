import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
A = list(map(int, input().split()))

t = 0
for i in A:
    t += i
    if t < 0:
        t = 0

print(t)