import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, m = map(int, input().split())
x = []; y = []
for _ in range(m):
    xy = list(map(int, input().split()))
    x.append(xy[0])
    y.append(xy[1])

arr = [[] for _ in range(n)]
for i in range(m):
    arr[x[i]-1].append(y[i])
    arr[y[i]-1].append(x[i])
print(arr)