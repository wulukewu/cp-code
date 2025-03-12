import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
H = list(map(int, input().split()))

det = True
for i in range(n-1):
    if H[i+1] > H[0]:
        print(i+2)
        det = False
        break

if det:
    print(-1)