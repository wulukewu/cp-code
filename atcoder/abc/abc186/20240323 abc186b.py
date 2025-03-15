import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

h, w = map(int, input().split())
s = 0; m = 101
for _ in range(h):
    a = list(map(int, input().split()))
    s += sum(a)
    n = min(a)
    if n < m: m = n
ans = s - h * w * m
print(ans)