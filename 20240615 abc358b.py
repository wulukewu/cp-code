import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, a = map(int, input().split())
T = list(map(int, input().split()))
T.sort()

t = T[0] + a
print(t)
for i in range(n-1):
    if T[i+1]-T[i]>a:
        t = T[i+1] + a
        print(t)
    else:
        t = t + a
        print(t)
