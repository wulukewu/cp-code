import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, t, p = map(int, input().split())
L = list(map(int, input().split()))
L.sort()

ans = t-L[(-1)*p]
if ans < 0:
    print(0)
else:
    print(ans)