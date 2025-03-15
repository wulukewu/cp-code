import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
A = list(map(int, input().split()))

t = (n-1) // (k-1)
s = (n-1) % (k-1)
if s > 0:
    t += 1
print(t)