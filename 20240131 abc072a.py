import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

X, t = map(int, input().split())

if X >= t:
    ans = X - t
else:
    ans = 0

print(ans)