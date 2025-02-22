import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input())
a = list(map(int, input().split()))

arr = [0] * (10**5+3)

for i in a:
    b = [i-1, i, i+1]
    for j in b:
        arr[j] += 1

x = max(arr)
# X = arr.index(x)
print(x)