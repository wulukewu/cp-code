import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
l = []
r = []

ans = 0
for _ in range(n):
    l_, r_ = map(int, input().split())
    l.append(l_)
    r.append(r_)

for i in range(n):
    for j in range(i+1, n):
        # print(i, j)
        det = l[j] > r[i] or r[j] < l[i]
        if not det:
            ans += 1

print(ans)