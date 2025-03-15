import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
H = list(map(int, input().split()))

break_det = False
for i in range(n):
    if m >= H[i]:
        m -= H[i]
    else:
        break_det = True
        break

if not break_det:
    i = n

print(i)