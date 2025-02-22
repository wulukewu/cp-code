import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, l, r = map(int, input().split())

arr = []
for i in range(n):
    j = i+1
    if l<=j and j<=r:
        arr.append(r-j+l)
    else:
        arr.append(j)

arr = map(str, arr)
t = ' '.join(arr)
print(t)